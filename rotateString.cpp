#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string rotating(int len, char arr[], int space){
    int j=0;
    int index=0;
    index=(index+space)%len;
    if(index==j){
        string newStr(arr);
        return newStr;
    }
    for(int i=0; i<len-1; i++){
        swap(arr[j], arr[index]);
        index= (index+space)%len;
        if(index==j){
            j++;
            index=(space+j)%len;
            i++;
        }
    }
    string newStr(arr);
    return newStr;
}

int main()
{
    string str;
    cout << "Enter a string." << endl;
    cin >> str;
    int len = str.length();
    int space;
    cout << "How many shifts do you want?" << endl;
    cin >> space;
    if(space ==0||len==1){
        cout << str;
        return 0;
    }
    char arr[len];
    strcpy(arr, str.c_str());

    string newStr=rotating(len, arr, space);
    cout << newStr;
    return 0;
}
