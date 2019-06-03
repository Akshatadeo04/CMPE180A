// time complexity = O(n2)
// space complexity = O(1)

#include <iostream>
#include <vector>
using namespace std;

enum direction {leftx, rightx};

struct asteroid_t {
    int m; // Mass
    direction d; // Direction
};

typedef struct asteroid_t Asteroid;

int countHits(vector <asteroid_t> a){
    if(a.size()<=0){
        return 0;
    }
    int hits=0;
    if(a[0].d == 1){
        hits++;
    }
    for(int i=1; i< a.size(); i++){
        if(a[i].d == 1){
            hits++;
        }
        else{
            for(int j=i; j>0; j--){
                if(hits == 0){
                    break;
                }
                if(a[i].d != a[j-1].d){
                    if(a[i].m > a[j-1].m){
                        hits--;
                    }
                    else if (a[i].m == a[j-1].m){
                        hits--;
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return hits;
}

int main()
{
    vector <asteroid_t> stones;

    stones.push_back ({8, rightx});
    stones.push_back ({1, rightx});
    stones.push_back ({7, rightx});
    stones.push_back ({2, rightx});
    stones.push_back ({5, rightx});
    stones.push_back ({0, rightx});
    stones.push_back ({6, rightx});
    stones.push_back ({3, rightx});
    stones.push_back ({9, rightx});
    stones.push_back ({4, rightx});

    cout << countHits(stones);
    return 0;
}
