#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Inf 0x7fffffff

double y_soft[] = {-13.9526409630343, 11.2187276624557, -8.38128949252312, 4.78345138259717, 26.9987125227201,
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

int H[] = {0,0,0,1,1,0,1,0,0,1,1,1,0,1,0,1,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,0,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,0,0,1,1,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,0,1,0,0,0,0,1,1,0,0,0,1,0,1,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
    1,1,0,1,1,1,1,1,0,1,0,0,1,1,1,1,0,1,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,0,1,1,0,0,1,0,0,1,0,1,1,1,1,0,1,1,0,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,
    1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,0,0,1,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,1,0,1,1,0,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,  
    0,1,0,0,0,0,1,0,1,1,1,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,1,1,0,1,0,1,1,1,1,1,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,1,1,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,
    1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,0,1,1,0,1,0,0,0,0,1,1,1,0,0,0,1,0,1,1,1,1,1,1,0,0,1,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,
    1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,1,0,1,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
    1,1,1,0,0,0,0,1,1,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,1,1,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,
    1,1,1,0,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,
    0,1,0,1,1,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0,1,0,1,1,0,0,1,1,0,1,1,0,0,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
    1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,1,0,1,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
    0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,0,1,0,1,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,1,0,1,1,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}; 

int findMax(int a, int b) {
    return !(b > a) ? a : b;
}

void copy_vector(int *v1,int *v2,int n){
    int i;
    for(i=0; i<n; i++){
        v1[i] = v2[i];
    }
}

void print_patterns_mapping(int i,int j,int** patterns,int* sorted_list,int w){
    printf("\nPattern: ");

    for (j = 0; j < w; j++) {
    printf("%d ", patterns[i][j]);
    }
    printf("(combination of least reliable bits to be flipped)\n");
    printf("Mapping: ");

    for (j = 0; j < w; j++) {
    printf("%d->%d\t", patterns[i][j],sorted_list[patterns[i][j]-1]);
    }
}

void print_vector(int *vector,int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d",vector[i]);
    }
}

void print_indices(int *vector,int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d\t",vector[i]);
    }
}

void hard_dec(int* y_hard,double *llr,int n){
    int i;
    
    for(i=0; i<n; i++){
        if(llr[i] >= 0){
           y_hard[i] = 0;
        }
        else{
            y_hard[i] = 1;
        }
    }
    printf("y_hard:");
    print_vector(y_hard,n);
}

int memb_check(int *y, int *H,int n,int s){
    
    int syndrome;
    int i,j; 

    printf("\nSyndrome check: ");
    for (i = 0; i < s; i++) {
         syndrome = 0;
            for (j = 0; j < n; j++) {
                syndrome ^= (y[j] * H[i*n +j]);
            }
            printf("%d",syndrome);
            if(syndrome == 1){
                printf("\tFound '1' -> not all-zero vector");
                return 1;
            }
    }

    return 0;
}

void bitonic_sort(double *arr,int *ind_order,int n) {
    int i, j, w, l, temp_index;
    double temp;

    for (w = 2; w <= n; w *= 2) {
        for (j = w / 2; j > 0; j /= 2) {
            for (i = 0; i < n; i++) {
                l = i ^ j;  // bitwise XOR
                if (l > i) { //compare and swap
                    if (((i & w) == 0 && arr[i] > arr[l]) ||  // ascending
                        ((i & w) != 0 && arr[i] < arr[l])) {  // descending
                        // swap arr[i] and arr[l]
                        temp = arr[i];
                        arr[i] = arr[l];
                        arr[l] = temp;
                        
                        temp_index = ind_order[i];
                        ind_order[i] = ind_order[l];
                        ind_order[l] = temp_index;
                    }
                }
            }
        }
    }
}

int* sorter(double *llr,int n){
    int i;
    int* ind_order = (int*)calloc(n,sizeof(int));
    double* reliability = (double*)calloc(n,sizeof(double));

    for(i=0; i<n; i++){
        reliability[i] = fabs(llr[i]); //reliability is the absolute value of LLR
        ind_order[i] = i;   //initialize permutation vectors//
    }
    bitonic_sort(reliability,ind_order,n);
    
    printf("\nSorting LLRs in ascending order\n");
    /*print_vector(reliability);*/
    
    //Corresponding indices//
    printf("\nCorresponding indices\n");
    print_indices(ind_order,n);
    printf("\n");
    
    free(reliability);

    return ind_order;
}

void mountain_build(int *u, int kk, int w, int W1, int n1){
    int i,W2,q,r;

    for(i = kk + 1; i < w; i++)
        u[i] = u[kk];
    W2 = W1;
    for( i = 0; i < w; i++)
        W2 -= u[i];
    q = floor( W2 / (n1 - u[kk]) );
    r = W2 - q*(n1 - u[kk]);
    if (q != 0){
        for(i = w-q; i < w; i++)
            u[i] = n1;
    }
    if (w > q)
        u[w-q-1] = u[w-q-1] + r;
}

int** pattern_generator(int* partitions,int W,int n,int w) {
    int W1=W-w*(w+1)/2; 
    int n1=n-w;
    int i, k;

    int* u = (int*)calloc(n,sizeof(int));
    int* d = (int*)calloc(n,sizeof(int));
    int* D = (int*)calloc(n,sizeof(int));

    int** patterns = (int**)calloc(n,sizeof(int*));
    *partitions = 0;

     // The Landslide algorithm is applied to achieve partitioning 𝑊
     // into 𝑤 distinguished parts with maximum value of 𝑛; The
     // partition problem is first converted to partitioning 𝑊′ into 𝑤 
     // repeatable parts with maximum value of 𝑛′; 
     // Mapping from the latter partition to the former one is simply achieved by adding 1, 2, 3, 4 individually
     // Initial pattern
     for (i = 0; i < w; i++){
        u[i] = 0;
     }
     mountain_build(u, 0, w, W1, n1);

    while (1) {
        //Record partition
        patterns[*partitions] = (int*)calloc(w,sizeof(int));
        for (i = 0; i < w; i++)
            patterns[*partitions][i] = u[i] + (i + 1);
        (*partitions)++;

        //Evaluate drops
        for (i = 0; i < w - 1; i++){
            d[i] = u[i + 1] - u[i];
        }

        d[w - 1] = 0;
        D[w - 1] = d[w - 1];

        for (i = w - 2; i >= 0; i--){
            D[i] = D[i + 1] + d[i];//Evaluate accumulated drops
        }

        if (D[0] < 2) break; // No more partitions

        k = 0;
        for (i = w - 1; i > 0; i--) {
            if (D[i] >= 2) {
                k = i;
                break;
            }
        }

        u[k]++;
        mountain_build(u, k, w, W1, n1);
    
    }
    free(u);
    free(d);
    free(D);

    return patterns;
   
}

int* error_generator(int *sorted_list,int *pattern,int *y_hard,int w,int n){
    int i;
    int* tep = (int* )calloc(n,sizeof(int));
    int* y_guessed = (int* )calloc(n,sizeof(int));

     //initialize tep//
     for (i = 0; i < n; i++){
        tep[i] = 0;
    }

    for(i=0; i<w; i++){
      tep[sorted_list[pattern[i]-1]] = 1;
    }

    printf("\nTEP: ");
    print_vector(tep,n);
    
    for (i = 0; i < n; i++){
        y_guessed[i] = y_hard[i] ^ tep[i];
    }
    
    printf("\ny_guessed: ");
    print_vector(y_guessed,n);

    free(tep);
    
    return y_guessed;
}

void ORBGRAND(int *y_decoded,int *n_guesses,double *y_soft,int *H,int n,int s,int n_guesses_max){

    int i,j,sy,partitions,W=0,w=0,temp,decoded=0;
    int *sorted_list,**patterns,*y_guessed;
    int* y_hard = (int*)calloc(n,sizeof(int));
    y_decoded = (int* )calloc(n,sizeof(int));


    hard_dec(y_hard,y_soft,n);
    n_guesses[0]=1;  //First query is hard y//
    if(n_guesses_max == 0){
        n_guesses_max = Inf;
    }
    sy = memb_check(y_hard,H,n,s);

    if (sy == 0){
         printf("\nSuccessful Decoding -> y_decoded: ");
         copy_vector(y_decoded, y_hard, n);
         print_vector(y_decoded,n);
         decoded=1;
    }
    else{
        printf("\nSorter begins\n");
        sorted_list = sorter(y_soft,n);
    
    while(n_guesses[0]<n_guesses_max){
        W++; //Increment logistic weight
        temp = 1+2*n;
        w = findMax(1, ceil((temp-sqrt(pow(temp, 2)-8*W))/2));  //Increment Hamming weight
            
        while (w<=floor((sqrt(1+8*W)-1)/2)){
                /*landslide algorithm for generating integer partitions*/
                printf("\nLW:%d\tHW:%d\n",W,w);

                patterns = pattern_generator(&partitions,W,n,w);
                for (i = 0; i < partitions; i++){
                    n_guesses[0]++;

                    print_patterns_mapping(i,j,patterns,sorted_list,w);

                    y_guessed = error_generator(sorted_list,patterns[i],y_hard,w,n);

                    sy = memb_check(y_guessed,H,n,s);
                        if (sy == 0){
                            copy_vector(y_decoded,y_guessed,n);
                            printf("\tSuccessful Decoding\ny_decoded: ");
                            print_vector(y_decoded,n);
                            decoded=1;
                            printf("\nNumber of guesses performed: %d",n_guesses[0]);

                            free(y_guessed);
                            free(y_decoded);
                            break;
                        }
                        else{
                            printf("\nGenerate new TEP");
                        }
                        
                        free(y_guessed);    
                        free(patterns[i]);
                        printf("\n");       
                }  
                free(patterns);
                w++;
        }
        if(decoded) break;
    }
    } 
    free(y_hard);
    free(sorted_list);
}

int main(){
    int n_guesses,n_guesses_max;
    int *y_decoded;
    int n,k,s;
    n=128;
    k=116;
    s=n-k;
    ORBGRAND(y_decoded,&n_guesses,y_soft,H,n,s,n_guesses_max);
    return 0;
}