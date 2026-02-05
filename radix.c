
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define max 200000

int getMax(int a[], int n)
{
    int i, mx = a[0];
    for (i = 1; i<n; i++)
    {
        if(mx < a[i])
            mx = a[i];
    }
    return mx;
}

void countSort(int a[], int n, int exp)
{
    int count[10] = {0};
    int output[n], i;

    for (i=0; i<n; i++)
        count[(a[i] / exp) % 10] ++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n)
{
    int exp;
    int m = getMax(a, n);

    for ( int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

void display(int a[], int n)
{
    int i;
    for (i = 0;i < n;i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int i, a[max], n;
    printf("Enter n: ");
    scanf("%d", &n);

    //For time
    srand(time(NULL));
    time_t t1,t2;
    double d;

    // Create the array
    for (i=0;i<n;i++){
        a[i]= rand()%100000;
    }

    display(a, n); //display the digits
    //t1 = time(NULL);
    radixSort(a,n);
    //t2 = time(NULL);
    display(a,n);
    //d = difftime(t2,t1);
    //printf("The time is %lf seconds.\n",d);

    return 0;
}
