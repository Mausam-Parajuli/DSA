#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

void Merge(int A[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int size = r - l + 1;
    int *B = (int *)malloc(size * sizeof(int));

    while (i <= m && j <= r)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= m)
        B[k++] = A[i++];
    while (j <= r)
        B[k++] = A[j++];
        
    for (i = l, k = 0; i <= r; i++, k++)
        A[i] = B[k];

    free(B);
}

void MergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSort(A, l, m);
        MergeSort(A, m + 1, r);
        Merge(A, l, m, r);
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[MAX], i, n;
    srand(time(NULL));
    time_t t1, t2;
    double difference;
    printf("Enter n: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }
    display(A , n);
    t1 = time(NULL);
    MergeSort(A , 0 , n-1);
    t2 = time(NULL);
    printf("After sorting is:  \n ");
    display(A , n);


    difference = difftime(t2 , t1);
    printf("The time is %lf seconds ", difference);
    return 0;
}