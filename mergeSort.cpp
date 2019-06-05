#include <iostream>
using namespace std;

void merging(int *arr, int *left, int *right, int len_left, int len_right){
    int i=0; int j=0; int k=0;
    while(i<len_left && j < len_right){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(j < len_right){
        arr[k] = right[j];
        j++;
        k++;
    }
    while(i<len_left){
        arr[k] = left[i];
        i++;
        k++;
    }
}

void mergeSort(int *arr,int n){
    if(n <=1 ) return;
    int j=0;
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    for(int i=0; i<mid;i++){
        left[i] = arr [i];
    }
    for(int i=mid; i<n;i++){
        right[j] = arr[i];
        j++;
    }
    mergeSort(left, mid);
    mergeSort(right,(n-mid));
    merging(arr,left,right,mid,(n-mid));
}

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1,5,9,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,n);
    display(arr,n);
    return 0;
}
