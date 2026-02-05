//Implementation of Factorial using Recursion

#include<stdio.h>

long int tailFact(int n, long int a)
{
    if(n==0)
        return a;
    else 
        return tailFact(n-1,a*n);
}
int main()
{
    int n;
    printf("Enter a number you want to find Factorial of :\t");
    scanf("%d",&n);
    printf("Factorial is %d\n",tailFact(n,1));

    return 0;
}
