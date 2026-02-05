
#include<iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

#define max 200000

void shell_sort(int a[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;
            for ( j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}

void display(int a[],int n){
    int i;
    for (i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n,a[max],i;
    srand(time(NULL));
    //time_t t1,t2;
    double d;
    cout<<"Enter n: ";
    cin>>n;
    for (i=0;i<n;i++){
        a[i]= rand()%10000;
    }
    display(a,n);
    //t1 = time(NULL);
    shell_sort(a,n);
    //t2 = time(NULL);
    display(a,n);
    //d = difftime(t2,t1);
    //cout<<"The time is %lf seconds.\n"<<d<<endl;

    return 0;
}