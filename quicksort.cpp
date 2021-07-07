#include<iostream>
using namespace std;

int partition(int arr[], int i, int j)
{
    int p = arr[i];
    while(1)
    {
        while(arr[i]<p) i++;
        while(arr[j]>p) j--;
        swap(arr[i],arr[j]);
        if(i>j) return i;
    }
}


void quicksort(int arr[], int i, int j)
{
    if(i < j)
    {
        int p = partition(arr, i, j);
        quicksort(arr, i, p-1);
        quicksort(arr, p+1, j);   
    }
}  


int main()
{
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)cin>>arr[i];

    quicksort(arr,arr[0],arr[n-1]);
    for(int i=0; i<n; i++)cout<<arr[i];
    
    return 0;
}