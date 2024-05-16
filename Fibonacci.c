#include <stdio.h>
#include <stdlib.h>


int len=1;

double next_fib_number(double first_num, double second_num){
    return first_num+second_num;
}

double fibonachi (double ordinal_num)
{
    double fib_num, fib_curr=1, fib_pref=1;
    if (ordinal_num<=0){
        fib_num=-1;
    }
    if( ordinal_num == 1 ){
        fib_num=0;
    }
    if( ordinal_num == 2 ){
        fib_num=1;
    }
    if( ordinal_num == 3 ){
        fib_num=1;
    }
    if( ordinal_num > 3 ) {
        for( ;ordinal_num>3;ordinal_num--){
            fib_num=next_fib_number(fib_curr, fib_pref);
            fib_pref=fib_curr;
            fib_curr=fib_num;
        }
    }
    return fib_num;
}

void compare(double a, double b){
    if (a==b){
        printf("True\n");
    }
    else printf("Error:d a='%f', b='%f'\n", a, b);
}

int* expend_arr(int* arr){
    int *arr_add;
    int t; //переменная, нужная для перечисления элементов в массиве, для замены одного массива другим
    arr_add=(int*) malloc(len * sizeof(int));
    for(t=0;t<len;t++){
        arr_add[t]=arr[t];
    }
    free(arr);
    arr=(int*) malloc(len * sizeof(int));
    for(t=0;t<len;t++){
        arr[t]=arr_add[t];
    }
    free(arr_add);
    arr[len-1]=0;
    return arr;
}

void sum_of_arr(int** arr1, int** arr2){
    int t;//переменная, для перебирания элементов массива
    int* arr_add;
    arr_add=(int*) malloc(len * sizeof(int));
    for(t=0;t<len;t++){
        arr_add[t]=0;
    }
    for(t=0;t<len;t++){
        if(((arr_add[t])+(*arr1)[t]+(*arr2)[t]<10)){
            arr_add[t]=(arr_add[t]+(*arr1)[t]+(*arr2)[t]);
        }
        else{
            if(t+1 == len){
                len++;
                *arr1=expend_arr(*arr1);
                *arr2=expend_arr(*arr2);
                arr_add=expend_arr(arr_add);
            }
            arr_add[t+1]++;
            arr_add[t]=(arr_add[t]+(*arr1)[t]+(*arr2)[t])%10;
        }
    }
    for(t=0;t<len;t++){
        (*arr2)[t]=arr_add[t];
    }
    int* l;
    l=*arr1;
    *arr1=*arr2;
    *arr2=l;
    free(arr_add);
}

int fibonachi_arrs(){
    int *arr1, *arr2;
    int ord_num;
    int t; //переменная, нужая для перебора элементов массива
    printf("Select ordinal number\n");
    scanf("%d", &ord_num);
    if(ord_num == 1){
        printf("Answer is 0");
        return 0;
    }
    if(ord_num == 2){
        printf("Answer is 1");
        return 0;
    }
    if(ord_num == 3){
        printf("Answer is 1");
        return 0;
    }
    if(ord_num<0){
        printf("Err");
        return 0;
    }
    ord_num=ord_num-4;
    arr2 = (int*) malloc(1 * sizeof(int));
    arr1 = (int*) malloc(1 * sizeof(int));

    if(arr1 == NULL || arr2 == NULL) {
        printf("Error! memory not allocated.");
        return 0;
    }
    arr1[0]=1;
    arr2[0]=1;

    for(t=0;t<=ord_num;t++){
        sum_of_arr(&arr1, &arr2);
    }
    for(t=len-1;t>=0;t--){
        printf("%d", arr1[t]);
    }
    free(arr1);
    free(arr2);

    return 0;
}


int main() {
    compare(fibonachi(82), 37889062373143906);
    fibonachi_arrs();
}

