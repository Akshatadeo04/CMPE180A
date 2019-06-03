#include <iostream>
#include <string>
using namespace std;

string mix(string a, string b){
    using namespace std;
    int len_a = a.length();
    int len_b = b.length();
    string mixed_str = "";
    int i=0;
    int j=0;
    int k=0;
    while(i<a.length() && j<b.length()){
        if(k==0){
            mixed_str = mixed_str + a[i];
            i++;
            k++;
        }
        else{
            mixed_str = mixed_str + b[j];
            j++;
            k--;
        }
    }
    if(i<a.length()){
        mixed_str = mixed_str + a.substr(i,a.length()-1);
    }
    if(j<b.length()){
        mixed_str = mixed_str + b.substr(j,b.length()-1);
    }
    return mixed_str;
}

int main()
{
    string first, second;
    cout << "Enter first string." << endl;
    getline(cin,first);
    cout << "Enter second string." << endl;
    getline(cin,second);
    string finalStr = mix(first, second);
    cout << finalStr;
    return 0;
}
