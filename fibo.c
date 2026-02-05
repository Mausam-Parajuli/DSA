#include<stdio.h>
#define max 100
int table[max];

int fiboUsingRecursion(int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return fiboUsingRecursion(n-1) + fiboUsingRecursion(n-2);
}
int fiboUsingMemo(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }   
    if (table[n] != 0) {
        return table[n];
    }
    table[n] = fiboUsingMemo(n - 1) + fiboUsingMemo(n - 2);
    return table[n];
}


int main()
{
    int num,i,choice,x,result;
    for(i=0;i<max;i++){
        table[i]=0;
    }
    printf("Enter a number for Nth term of Fibonacci series:\n");
    scanf("%d",&num); 
    printf("Enter \n1.Without Memoization \n2.With Memoization\n");
    scanf("%d",&choice);
    if(choice==1){
        result = fiboUsingRecursion(num);
        printf("The %dth term is %d",num,result);
    }
    else if(choice==2){
        result = fiboUsingMemo(num);
        printf("The %dth term is %d",num,result);
    }
    

    return 0;
}