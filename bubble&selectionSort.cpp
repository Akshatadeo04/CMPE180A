#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n){
    int i=0;
    while(i<n){
        for(int j=0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        n--;
    }
    for(int i=0; i<5 ; i++){
        cout << arr[i] << " ";
    }
}

void selectionSort(int arr[], int n){
    int i=0;
    while(i<(n-1)){
        int mini = i;
        for(int j=i; j<n; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
            swap(arr[mini],arr[i]);
        }
        i++;
    }
    for(int i=0; i<5 ; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1,5,9,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    //selectionSort(arr,n);
    return 0;
}
