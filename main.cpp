#include <iostream>
#include <list>
using namespace std;

class Hash{
    int bucket;
    list<int> *table;
public:
    Hash(int b){
        bucket = b;
        table = new list<int> [bucket];
    }
    void inserting(int key){
        int index = key%bucket;
        table[index].push_back(key);
    }
    void deleting(int key){
        int index = key%bucket;
        list<int> :: iterator i;
        for(i = table[index].begin(); i!=table[index].end() ; i++){
            if(*i == key) break;
        }
        if(i != table[index].end()){
            table[index].erase(i);
        }
        else{
            cout << "key not found";
        }
    }
    void display(){
        for(int i=0; i<bucket; i++){
            for(auto x : table[i]){
                cout << x;
            }
        }
    }
};

int main(){
    int arr[] = {1,4,8,3,7,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    Hash h(5);
    for(int i=0; i<n ; i++){
        h.inserting(arr[i]);
    }
    h.deleting(1);
    h.display();
    return 0;
}
