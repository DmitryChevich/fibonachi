#include <stdio.h>
#include <stdlib.h>

int next_fib_number(int first_num, int second_num){
    return first_num+second_num;
}

int main ()
{
    int fib_num, fib_curr=1, fib_pref=1;
    printf("What number?\n");
    int ordinal_num;
    scanf("%d", &ordinal_num);
    if (ordinal_num<=0){
        printf("NULL");
    }
    if( ordinal_num == 1 ){
        printf("Answer is 0");
    }
    if( ordinal_num == 2 ){
        printf("Answer is 1");
    }
    if( ordinal_num == 3 ){
        printf("Answer is 1");
    }
    if( ordinal_num > 3 ) {
        for( ;ordinal_num>3;ordinal_num--){
            fib_num=next_fib_number(fib_curr, fib_pref);
            fib_pref=fib_curr;
            fib_curr=fib_num;
        }
    printf("Answer is %d", fib_num);
    }
    return 0;
}
