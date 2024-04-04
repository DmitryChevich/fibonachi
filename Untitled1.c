#include <stdio.h>
#include <stdlib.h>

int next_fib_number(int first_num, int second_num){
    return first_num+second_num;
}

int fibonachi (int ordinal_num)
{
    int fib_num, fib_curr=1, fib_pref=1;
    if (ordinal_num<=0){
        fib_num=NULL;
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

void compare(int a, int b){
    if (a==b){
        printf("True\n");
    }
    else printf("Error:d a='%d', b='%d'\n", a, b);
}

int main() {
    compare(fibonachi(8), 13);
    compare(fibonachi(0), NULL);
    compare(fibonachi(1), 0);
    compare(fibonachi(3), 1);
    compare(fibonachi(5), 3);
    compare(fibonachi(10), 34);
    compare(fibonachi(12), 89);
    compare(fibonachi(23), 17711);
}
