#include<stdio.h>
int Moves = 0;

void toh(int n,char src,char dst,char tmp){
    if(n==1){
        printf("Move disc %d from %c to %c \n",n ,src ,dst);
        Moves++;
    }
    else
    {
        toh(n-1,src,tmp,dst);
        printf("Move disc %d from %c to %c \n",n,src,dst);
        toh(n-1,tmp,dst,src);
        Moves++;
    }
}

int main()
{
    int n;
    char src,dst,tmp;
    src = 'A';
    dst = 'C';
    tmp = 'B';
    printf("Enter the no of discs:\n");
    scanf("%d",&n);
    toh(n,src,dst,tmp);
    printf("Process completed in %d moves.",Moves);

    return 0;
}