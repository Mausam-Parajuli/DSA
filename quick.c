#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 500000

void quicksort(int a[],int l,int r);
int partition(int a[],int l, int r);

void quicksort(int a[],int l,int r){
    int p;
    if(l<r){
        p = partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}
int partition(int a[],int l, int r){
    int x = l,y = r,temp;
    int pivot = a[l];
    while(x<y){
        while(a[x] <= pivot && x <= r)
            x++;
        while(a[y] > pivot && y>=l )
            y--;
        if(x<y){
            temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }
    }
    temp = a[l];
    a[l] = a[y];
    a[y] = temp;
    return y;
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
        a[i]= rand()%100000;
    }
    //display(a,n);
    t1 = time(NULL);
    quicksort(a,0,n-1);
    t2 = time(NULL);
    //display(a,n);
    d = difftime(t2,t1);
    printf("The time is %lf seconds.\n",d);

    return 0;
}