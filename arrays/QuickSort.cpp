#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = high;
    int j = low;
    for(int i = low;i < high; i++){
        if(arr[i] <= arr[pivot]){
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
    swap(&arr[j], &arr[pivot]);
    return j;
}

void quickSort(int arr[], int low, int high){
    
    if(low >= high)return;
    
    int p = partition(arr, low, high);
    
    quickSort(arr, low, p-1);
    quickSort(arr, p+1, high);
}

int main()
{
    int arr[] = {7, 9, 4, 232, 3, 8};
    quickSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
