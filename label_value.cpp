#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    int counting=0;
    string label;
    string smallest_label;
    string largest_label;
    float smallest_value;
    float largest_value;
    float value;
    cout << "Input file:" << endl;
    string input_file;
    cin>> input_file;
    ifstream in;
    //ifstream in(input_file.c_str());
    in.open(input_file.c_str());

    if(in.fail()){
        cerr << "Sorry !!! Something went wrong while opening a file.";
        exit(1);
    }

    while(!in.eof()){
        if(counting ==0){
            in >> label >> value;
            smallest_label=label;
            largest_label=label;
            smallest_value=value;
            largest_value=value;
            counting++;
        }
        else{
            in >> label >> value;
            if(smallest_value>value){
                smallest_value=value;
                smallest_label=label;
            }
            if(largest_value<value){
                largest_value=value;
                largest_label=label;
            }
        }
    }

    cout << left << setw(50) << largest_label << " " << right << setw(12) << fixed << setprecision(2) << largest_value << endl;
    cout << left << setw(50) << smallest_label << " " << right << setw(12) << fixed << setprecision(2) << smallest_value << endl;

    in.close();
    return 0;
}
