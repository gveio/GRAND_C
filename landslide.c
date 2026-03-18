#include <stdio.h>
#include <stdlib.h>
#include <math.h>
GG
void mountain_build(int *u, int k, int w, int W1, int n1){
    int i,W2,q,r;

    for(i = k + 1; i < w; i++)
        u[i] = u[k];
    W2 = W1;
    for( i = 0; i < w; i++)
        W2 -= u[i];
    q = floor( W2 / (n1 - u[k]) );
    r = W2 - q*(n1 - u[k]);
    if (q != 0){
        for(i = w-q; i < w; i++)
            u[i] = n1;
    }
    if (w > q)
        u[w-q-1] = u[w-q-1] + r;
}

int* landslide(int W,int n,int w){
    int k,i,W1,n1;
        int* pattern = (int*)malloc(n * sizeof(int));
        int* u = (int*)malloc(n * sizeof(int));
        int* d = (int*)malloc(n * sizeof(int));
        int* D = (int*)malloc(n * sizeof(int));
    
        // The Landslide algorithm is applied to achieve partitioning 𝑊
        // into 𝑤 distinguished parts with maximum value of 𝑛; The
        // partition problem is first converted to partitioning 𝑊′ into 𝑤 
        // repeatable parts with maximum value of 𝑛′; 
        // Mapping from the latter partition to the former one is simply achieved by adding 1, 2, 3, 4 individually
    
            W1=W-w*(w+1)/2; 
            n1=n-w;
            //Start with empty vector and breaking at first index
            for (i = 0; i < w; i++)
                u[i] = 0;
            mountain_build(u,0,w,W1,n1);
           
            for (i = 0; i < w; i++)
                pattern[i] = u[i] + (i+1);

            //record the partition
            printf("\nDistinct integer partitions:\n");
            for(i=0; i<w; i++){
                printf("%d ", pattern[i]);
            }
            printf("\n");
       
            //Evaluate drops
            for (i = 0; i < w - 1; i++){
                d[i] = u[i+1] - u[i];
            }
    
            d[w-1] = 0;
            D[w-1] = d[w-1];
                for (i = 1; i < w; i++){
                    D[w-i-1] = D[w-i] + d[w-i-1]; //Evaluate accumulated drops
                }
                while( D[0] >= 2 ){ //Each loop generates a new integer partition
                    k = 0;
                    for (i = w-1; i > 0; i--){
                        if (D[i] >= 2){ //Find the last index with an accumulated drop >=2
                            k = i;
                            break;
                        }
                    }
                    u[k] ++; //Increase its index by one
    
                    mountain_build(u,k,w,W1,n1);
    
                    for (i = 0; i < w; i++){
                        pattern[i] = u[i] + (i+1);
                    }
    
                    //record the partition
                    for(i=0; i<w; i++){
                        printf("%d ", pattern[i]);
                    }
                    printf("\n");
    
                    for (i = 0; i < w - 1; i++){
                        d[i] = u[i+1] - u[i]; //Evaluate drops
                    }
                    d[w-1] = 0;
                    D[w-1] = d[w-1];
                    for (i = 1; i < w; i++){
                        D[w-i-1] = D[w-i] + d[w-i-1]; //Evaluate accumulated drops
                    }
                }        
            free(u);
            free(d);
            free(D);
       
        return pattern;
 }

int main(){
    int *pattern,w,W;
    pattern = landslide(104,128,13);
    return 0;
    
}