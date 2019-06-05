#include <iostream>

using namespace std;

int partitioning(int *arr, int first, int last){
    int pivot = arr[last];
    int pindex = first;
    for(int i=first; i<last; i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pindex]);
            pindex++;
        }
    }
    swap(arr[last],arr[pindex]);
    return pindex;
}

void quickSort(int *arr, int first, int last){
    if(first>=last) return;
    int pindex = partitioning(arr,first,last);
    quickSort(arr,first,pindex-1);
    quickSort(arr,pindex+1, last);
}

int main()
{
    int arr[] = {1,4,0,8,1};
    quickSort(arr,0,4);
    for(int i=0; i<5;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
