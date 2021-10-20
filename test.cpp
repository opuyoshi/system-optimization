#include<stdio.h>
#define N 4
#define B 6
/*
int sort(int value[], int weight[], int n, int order[]){
    int greedy[] = {0};
     //calculate greedy array
    for(int i = 0; i < 4; i++){
        greedy[i] = (value[i] / weight[i]);
    }

    int i, j, k;
    int max;

    for(i=0; i < n-1; i++){
        k = i;
        max= greedy[k];
        for(j=i+1; j<n; j++){
            if(greedy[j] > max){
                k =j;
                max = greedy[k];
            }
        }
        greedy[k] = greedy[i];
        greedy[i] = max;
        order[i] = k;
    }
        return *order;
}

int main(void){
    //initialize weight
    int weight[N] = {3, 2, 5, 4};
    //価値
    int value[N] = {2, 1, 8, 7};
   
    int order[N] = {0};
    //call sort algorithm
    sort(value, weight, N, order);

    //declear Dynamic Programming's valuable
    int dp[N][B+1];
    //initialize dp[][]
    for(int i=0; i < N; i++){
        for(int j=0; j < B+1; j++){
            dp[i][j] = 0;
        }
    }
    for(int i=0; i < N; i++){
        printf("%d",order[i]);
    }
 
    return 0;
}
*/
int main(void){
    printf("hello world\n");
    return 0;
}
