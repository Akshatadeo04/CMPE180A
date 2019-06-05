#include <iostream>
#include <cstdlib>
using namespace std;

int factorial(int x){
    if(x<0) exit(1);
    else if(x == 0 || x ==1) return 1;
    else return (x * factorial(x-1));
}

int fibonacci(int x){
    if(x<0) exit(1);
    else if(x == 0 || x ==1) return x;
    return (fibonacci(x-1)+fibonacci(x-2));
}

int main()
{
    cout << factorial(5) << endl;
    cout << fibonacci(5);
    return 0;
}
