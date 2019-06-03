#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool palindrome(string xyz){
    int k=0;
    char abc[xyz.length()];
    strcpy(abc, xyz.c_str());
    int j=(xyz.length()-1);
    for(int i=0; i<=j; ){
        if(isalpha(abc[i])&&isalpha(abc[j])){
            if(abc[i]==abc[j]){
                j--;
                i++;
                k++;
                continue;
            }
            else{
                return 0;
            }
        }
        else{
            if(!isalpha(abc[i])){
                i++;
            }
            if(!isalpha(abc[j])){
                j--;
            }
        }
    }
    if(k==0){
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    string str;
    cout << "Enter a string." << endl;
    cin >> str;
    bool check = palindrome(str);
    if (check == 0){
        cout << str << " isn't a palindrome.";
    }
    else{
        cout << str << " is a palindrome.";
    }
    return 0;
}
