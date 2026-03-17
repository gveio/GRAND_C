#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMax(int a, int b) {
    return !(b > a) ? a : b;
}

int main(){
    int n=128;
    int W=0,w=0,temp;

    while(1){
        W++; //Increment logistic weight
        temp = 1+2*n;
        w = findMax(1, ceil((temp-sqrt(pow(temp, 2)-8*W))/2));  //Increment Hamming weight
            printf("\nLW:%d\t",W);
        while (w<=floor((sqrt(1+8*W)-1)/2)){
                printf("HW:%d\t",w);
                w++;
        }
        if(W == 104) break;
    }
    return 0;
}
