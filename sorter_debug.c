#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void print_vector(double *vector, uint64_t n) {
    for (uint64_t i = 0; i < n; i++) printf("%6.2lf ", vector[i]);
    printf("\n");
}

void print_indices(uint32_t *vector, uint64_t n) {
    for (uint64_t i = 0; i < n; i++) printf("%3u ", vector[i]);
    printf("\n");
}

void bitonic_sort(double *arr, uint32_t *ind_order, uint64_t n) {
    uint64_t i, dist, seq_len, partner;
    double temp;
    uint32_t temp_index;
    int stage = 0;

    for (seq_len = 2; seq_len <= n; seq_len *= 2) {
        printf("\n=== Stage %d (seq_len = %llu) ===\n", ++stage, seq_len);

        for (dist = seq_len / 2; dist > 0; dist /= 2) {
            printf("  >> Substage (dist = %llu)\n", dist);
            for (i = 0; i < n; i++) {
                partner = i ^ dist;
                if (partner > i) {
                    int dir_asc = ((i & seq_len) == 0);
                    if ((dir_asc && arr[i] > arr[partner]) ||
                        (!dir_asc && arr[i] < arr[partner])) {
                        temp = arr[i];
                        arr[i] = arr[partner];
                        arr[partner] = temp;

                        temp_index = ind_order[i];
                        ind_order[i] = ind_order[partner];
                        ind_order[partner] = temp_index;
                    }
                }
            }
        }
    }
}

int main(void) {
    uint64_t n = 128;
    double y_data[] = {-13.9526409630343, 11.2187276624557, -8.38128949252312, 4.78345138259717, 26.9987125227201,
    -9.30263246418097, -12.1370407309178, -12.4680012993316, 8.44335096471555, 21.8448541841057, 
    11.9839141999517, 18.2081676198915, 18.6904546194771, -20.4058005551350, 9.35956182915252,
    13.5640615475346, 1.39332889223321, 17.9363960895396, 14.3849860686768, 12.7552391723131, 
    -9.75558442302411, -13.7806871774085, -12.4857040760719, 13.5671912629664, 8.98352597166392, 
    15.5331388403282, 22.0645370076752, 12.2677398408014, -2.96071201409288, -25.3781847843608, 
    -9.81821522699941, -10.1895467106233, 11.4326582173386, -19.8026801077095, -11.0339288862347, 
    21.8099306779021, 10.0234524253561, 16.9856674059590, -16.5570341049840, -5.63701251431570, 
    -5.32013340278400, 15.7505405772347, 14.1708988102053, -9.03283130181808, 7.44106620996482, 
    -24.5826526358927, -9.36829993107900, 12.0244182063578, -19.8682887883935, -8.37534340625206, 
    -27.0620755140353, 16.2603518279303, 1.90078428101974, 14.0390698523079, 12.0488062435829, 
    -18.7028354531763, 18.3795506776916, 7.69060872312832, 10.0834187684309, 20.6372930142873, 
    13.3273810229308, 21.4686676852339, 10.0275345759545, -17.1551357707401, 12.4480705572055, 
    -13.8897755153447, 5.77249711161889, -16.3405545793931, -18.7184161869791, -16.3813698012431, 
    14.7734865796042, 22.6829265312052, 22.1064203102005, -25.5668690868068, -22.3085796398760, 
    9.67291993998922, -13.8262070857423, 15.5978591711134, -6.36894620038483, 11.7556550553478, 
    -14.4983501490065, -13.5315863383337, 18.0749612758918, 4.32505648411743, -15.7959795219412, 
    13.6299774831279, 20.1761470016231, 9.44265458872117, -15.8920767851886, -6.55053160814318, 
    7.85925756709074, 19.6781963714559, -6.80317645678046, 6.77603999841652, 30.2402045429412, 
    -1.98310376339641, 12.9708194137054, -13.8548265971036, 24.6342947686015, 11.3589295746527, 
    -10.5042148665630, -18.0466643515509, -10.9783470724927, 16.7036223839604, -19.5690160753701, 
    -17.9629653458826, -12.5514096816450, -16.5927404859650, 16.4224851532145, 4.84814036804866, 
    17.5606410717674, -7.20178023854872, 7.88298684795811, -17.1929178315191, 14.9093001155096, 
    -12.6447372355973, 11.0025765918795, -12.6268167045996, -12.9617712399612, 15.6199085417807, 
    26.7929486422051, 9.43029976503900, 8.17273609845454, -14.4020568747641, -12.3934990761270, 
    23.8659213646972, 1.54568496554683, 18.4869389889476};
    const double LLR_max = 31.0;
    const int B = 6;
    const int B_mag = B - 1;

    // round n up to next power of two
    uint64_t n_effective = 1;
    while (n_effective < n) n_effective *= 2;

    // allocate arrays of size n_effective
    double *y_soft = (double *)calloc(n, sizeof(double));
    double *LLR = (double *)calloc(n, sizeof(double));
    double *LLR_mag = (double *)calloc(n_effective, sizeof(double));
    double *LLR_mag_q = (double *)calloc(n_effective, sizeof(double));
    uint32_t *sorted_list = (uint32_t *)calloc(n_effective, sizeof(uint32_t));
    uint32_t *sorted_list_q = (uint32_t *)calloc(n_effective, sizeof(uint32_t));

    for (uint64_t i = 0; i < n; i++) {
        y_soft[i] = y_data[i];
    }

    // Accurate (non-quantized)
    for (uint64_t i = 0; i < n; i++) {
        LLR_mag[i] = fabs(y_soft[i]);
        sorted_list[i] = i;
    }
    for (uint64_t i = n; i < n_effective; i++) {
        LLR_mag[i] = LLR_max; // pad with max magnitude
        sorted_list[i] = i;
    }

    bitonic_sort(LLR_mag, sorted_list, n_effective);

    printf("\nSorted accurate magnitudes (first %llu valid):\n", n);
    print_vector(LLR_mag, n);
    printf("Indices:\n");
    print_indices(sorted_list, n);

    // Quantized
    for (uint64_t i = 0; i < n; i++) {
        // Clip and quantize
        double L = fmax(fmin(y_soft[i], LLR_max), -LLR_max);
        LLR_mag_q[i] = round(fabs(L) / LLR_max * (pow(2, B_mag) - 1));
        sorted_list_q[i] = i;
    }
    for (uint64_t i = n; i < n_effective; i++) {
        LLR_mag_q[i] = pow(2, B_mag) - 1; // pad = 31
        sorted_list_q[i] = i;
    }

    bitonic_sort(LLR_mag_q, sorted_list_q, n_effective);

    printf("\nSorted quantized magnitudes (first %llu valid):\n", n);
    print_vector(LLR_mag_q, n);
    printf("Indices:\n");
    print_indices(sorted_list_q, n);

    free(y_soft);
    free(LLR);
    free(LLR_mag);
    free(LLR_mag_q);
    free(sorted_list);
    free(sorted_list_q);

    // Quantization vs Accurate Matching Metrics
    int index_matches = 0;
    double mag_error_sum = 0.0;

    for (uint64_t i = 0; i < n; i++) {
        if (sorted_list[i] == sorted_list_q[i])
            index_matches++;
        mag_error_sum += fabs(LLR_mag[i] - LLR_mag_q[i]);
    }

    double index_match_pct = 100.0 * (double)index_matches / (double)n;
    double avg_mag_error_pct = 100.0 * (mag_error_sum / (n * LLR_max));

    printf("\n===== Quantization Impact Summary =====\n");
    printf("Index order match: %.2f%% (%d / %llu)\n",
        index_match_pct, index_matches, n);
    printf("Average magnitude error: %.4f%% of LLR_max\n",
        avg_mag_error_pct);
    printf("=======================================\n");
    
    int relaxed_matches = 0;
    for (uint64_t i = 0; i < n; i++) {
        for (int delta = -1; delta <= 1; delta++) {
            int j = (int)i + delta;
            if (j >= 0 && j < (int)n && sorted_list[i] == sorted_list_q[j]) {
                relaxed_matches++;
                break;
            }
        }
    }
    double relaxed_match_pct = 100.0 * relaxed_matches / (double)n;
    printf("Relaxed index match (±1 position): %.2f%%\n", relaxed_match_pct);

    return 0;
}
