/*
0-1ナップサック問題の近似解を欲張り法によって求めるプログラムを作成せよ．
max :  2 * x1 + x2 + 8 * x3 + 7 * x4
sub to : 3 * x1 + x2 + 5 * x3 + 4 * x <= 6

注意点：
出来るだけ効率的なプログラムをめざすこと
ユーザー関数やできれば構造体変数を使って，簡潔で分かりやすいプログラムに
同じ処理/ひとかたまりと考えられる処理は関数に
コメントを書く
変数・関数は内容が分かりやすい名前を付ける
インデントで読みやすくする
*/


#include<stdio.h>
//define N as 4
#define N 4 

// sorting algorighm(bubble sort)
void bubble_sort(double x[], int index[], int n){
    double hold; //swap value(x[])
    int hold_num; //swap value(index[])
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(x[j] > x[j-1]){//swap 
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

    //calculate c_a[N]
    for(int i=0;i<N;i++){
        c_a[i] = double(value[i]) / double(weight[i]);
    }

    bubble_sort(c_a, index, N); //sorting c_a and index

    for(int i=0; i<N;i++){//put item in greedy algorithms
        if(weight[index[i]] <= b){
            x[index[i]] = 1;
            b = b - weight[index[i]];
        }
        else x[index[i]] = 0;
    }

    printf("近似解");
    printf("(x1, x2, x3, x4) = ");
    for(int i=0;i<N;i++){ //calculate goal value
        printf("%d, ",x[i]);
        sum = sum + value[i] * x[i];
    }
    printf("\n");
    printf("目的関数値 : %d",sum);

    return 0;
}
