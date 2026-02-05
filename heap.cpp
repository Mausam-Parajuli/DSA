#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
#define max 500000
void max_heapify(int a[],int i,int n){
    int l = 2*i, r=2*i+1, largest = i, temp;
    if (l<=n && a[l]>a[largest]){
        largest = l;
    }
    if (r<=n && a[r]> a[largest]){
        largest = r;
    }
    if (i != largest){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a,largest,n);
    }
}
void build_max_heap(int a[], int n){
    int i;
    for (i=n/2;i>=1;i--){
        max_heapify(a,i,n);
    }
}
void heap_sort(int a[],int n){
    int i,temp;
    build_max_heap(a,n);
    for (i=n;i>=2;i--){
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        n = n-1;
        max_heapify(a,1,n);
    }
}
void display(int a[],int n){
    int i;
    for (i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
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
    heap_sort(a,n);
    //t2 = time(NULL);
    display(a,n);
    //d = difftime(t2,t1);
    //cout<<"The time is %lf seconds.\n"<<d<<endl;

    return 0;
}