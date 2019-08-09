/*
0-1ナップサック問題の近似解を局所探索法によって求めるプログラムを作成せよ．
max :  2 * x1 + x2 + 8 * x3 + 7 * x4
sub to : 3 * x1 + x2 + 5 * x3 + 4 * x <= 6
ただし，初期解，近似，移動戦略は各自で決定してよい
*/


#include<stdio.h>
#include<string.h> //memmove
//define N as 4
#define N 4 

// sorting algorighm(bubble sort)
void bubble_sort(double x[], int index[], int n){
    double hold; //swap value(x[])
    int hold_num; //swap value(index[])
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(x[j] > x[j-1]){ //swap
                hold = x[j];
                hold_num = index[j];
                x[j] = x[j-1];
                index[j] = index[j-1];
                x[j-1] = hold;
                index[j-1] = hold_num;
            }
        }
    }
}



int main(void){
    //initialize valuable(x1 ~ x4)
    int x[N] = {0};
    //weight
    int weight[N] = {3, 1, 5, 4};
    //value
    int value[N] = {2, 1, 8, 7};
    //index
    int index[N] = {0, 1, 2, 3};
    //define c_a = value / weight
    double c_a[N] = {0};
    //define b
    int b = 6;
    //define goal value
    int sum = 0;
    //flip answer
    int x_ans[N] = {0};

    //calculate c_a[N]
    for(int i=0;i<N;i++){
        c_a[i] = double(value[i]) / double(weight[i]);
    }

    bubble_sort(c_a, index, N); //sorting c_a and index

    for(int i=0; i<N;i++){ //put item in greedy algorithms
        if(weight[index[i]] <= b){
            x[index[i]] = 1;
            b = b - weight[index[i]];
        }
        else x[index[i]] = 0;
    }

    printf("初期解(欲張り法による近似解)");
    printf("(x1, x2, x3, x4) = ");
    for(int i=0;i<N;i++){
        printf("%d, ",x[i]);
        sum = sum + value[i] * x[i];
    }
    for(int i=0;i<N;i++){
        x_ans[i] = x[i];
    }
    printf("\n");
    printf("初期値(欲張り法による目的関数値) : %d\n",sum);
    int ans_sum = sum;
    /*
    printf("\nx[N]\tvalue[N]\tweight[N]");
    for(int i=0;i<N;i++){
        printf("\n%d\t%d\t%d",x[i], value[i], weight[i]);
    }
    printf("\n"); //new line
    */

    int hold;
    b = 6;

    for(int i=0;i<N-1;i++){
        for(int j=i;j<N-1;j++){
            int pre_b = 0;
            int pre_sum = 0;
            hold = x[i];
            x[i] = x[j+1];
            x[j+1] = hold;
            //printf("\n%d\t%d\t%d\t%d\n",x[0], x[1], x[2], x[3]); //for debug
            for(int k=0;k<N;k++){
                pre_b =pre_b + weight[k] * x[k];
                pre_sum = pre_sum + value[k] * x[k];
            }
            //printf("pre_b = %d",pre_b); //display pre_b for debug
            //printf("\npre_sum = %d\n",pre_sum); //display pre_sum for debug
            //printf("b = %d\n",b);
            if(b >= pre_b){
                if(pre_sum > ans_sum){
                    //printf("x[N] changed!!\n"); //for dubug
                    ans_sum = pre_sum;
                    for(int p=0;p<N;p++){
                        x_ans[p] = x[p];
                    }
                }
            }
            hold = x[i]; 
            x[i] = x[j+1];
            x[j+1] = hold;
            /*
           printf("\nx(x1, x2,x3. x4) = ");
           for(int p=0;p<N;p++){
               printf("%d, ",x[p]);
            }
            printf("\nx_ans(x1, x2, x3, x4) = ");
            for(int p=0;p<N;p++){
                printf("%d, ",x_ans[p]);
            }*/
        }
        //printf("\n------------------------j loop finish ----------------------\n"); //for debug
    }
    printf("\n交換近傍，最適移動戦略により得られた近似解 : (x1, x2, x3, x4) = ");
    for(int i=0;i<N;i++){
        printf("%d, ",x_ans[i]);
    }
    printf("\n交換近傍，最適移動戦略により得られた目的関数解 : %d\n",ans_sum);
   return 0;
}

