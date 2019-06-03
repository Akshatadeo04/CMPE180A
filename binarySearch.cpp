#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
int binarySearch(T arr[], T val, int first, int last){
    while(first <= last){
        int mid = (first+last)/2;
        if (arr[mid]==val) return mid;
        else if(arr[mid] < val) first = mid+1;
        else last = mid-1;
    }
    cout << "not found." << endl;
    return -1;
}

int main()
{
    int arr[] = {1,2,4,5,7,9};
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    cout << binarySearch(arr, 3, 0, arr_len-1);
    return 0;
}
