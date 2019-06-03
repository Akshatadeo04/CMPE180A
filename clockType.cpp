#include <iostream>
using namespace std;

class clockType
{
public:
    clockType(){
        hr = 00;
        mini = 00;
        sec = 00;
    }
    void setTime(int hours, int minutes, int seconds){
        if(hours <=23 && hours >=0) hr = hours;
        else hr =00;
        if(minutes <=59 && minutes >=0) mini = minutes;
        else mini =00;
        if(seconds <=59 && seconds >=0) sec = seconds;
        else sec =00;
    }
    void getTime(int& hours, int& minutes, int& seconds) const{
        hours = hr;
        minutes = mini;
        seconds = sec;
    }
    void printTime() const{
        cout << hr << ":" << mini << ":" << sec << endl;
    }
    void incrementSeconds(){
        if(sec<59) sec++;
        else{
            sec=00;
            if(mini<59) mini++;
            else{
                mini=00;
                if(hr<23) hr++;
                else{
                    hr=00;
                }
            }
        }
    }
    void incrementMinutes(){
        if(mini<59) mini++;
            else{
                mini=00;
                if(hr<23) hr++;
                else{
                    hr=00;
                }
            }
    }
    void incrementHours(){
        if(hr<23) hr++;
                else{
                    hr=00;
                }
    }
    bool equalTime(const clockType& otherClock) const{
        if(hr == otherClock.hr && mini == otherClock.mini && sec == otherClock.sec)
            return 1;
        else
            return 0;
    }
private:
    int hr;
    int mini;
    int sec;
};

int main()
{
    clockType myClock;
    //const clockType otherClock;
    myClock.setTime(12,34,56);
    //otherClock.setTime(78,90,12);
    //myClock.getTime(01,02,03);
    myClock.incrementHours();
    myClock.incrementMinutes();
    myClock.incrementSeconds();
    //myClock.equalTime(const clockType& otherClock);
    myClock.printTime();
    //otherClock.equalTime(const clockType& myClock);
    //otherClock.printTime();
    //otherClock.getTime(56,74,92);
    //otherClock.setTime(01,29,38);
    //otherClock.incrementHours();
    //otherClock.incrementMinutes();
    //otherClock.incrementSeconds();
    return 0;
}
