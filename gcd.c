//Implementation of GCD or HCF using recursion

#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int a,b,result;
    printf("Enter two numbers you want HCF of:\n");
    scanf("%d%d",&a,&b);
    if(b>a)
        result = gcd(a,b);
    else 
        result = gcd(b,a);

    printf("The HCF is %d\n",result);

    return 0;
}
