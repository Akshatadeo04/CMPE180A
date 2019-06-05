#include <iostream>
#include <string>

using namespace std;

int deci_to_binary(int x, int i, int total){
    if(x == 0) return (total);
    if(x == 1) return (1*i+total);
    int quo = x/2;
    int rem = x%2;
    total = total + (i*rem);
    i=i*10;
    deci_to_binary(quo,i,total);
}

int main()
{
    int i=1;
    int total=0;
    cout << deci_to_binary(5,i, total);
    return 0;
}
