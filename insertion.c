#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 200000

void insertion_sort(int a[],int n){
    int i,j,hold;
    for (i=1;i<n;i++){
        hold = a[i];
        for (j=i-1;j>0 && a[j] > hold;j--){
            a[j+1] = a[j];
        }
        a[j+1] = hold;
    }
}
void display(int a[],int n){
    int i;
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int i,a[max],n;
    srand(time(NULL));
    time_t t1,t2;
    double d;
    printf("Enter n: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        a[i]= rand()%10000;
    }
    display(a,n);
    t1 = time(NULL);
    insertion_sort(a,n);
    t2 = time(NULL);
    display(a,n);
    d = difftime(t2,t1);
    printf("The time is %lf seconds.\n",d);

    return 0;
}