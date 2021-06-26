#include <bits/stdc++.h>
using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;


    public:
        int hours(){
            if(hour!=NULL)
                return hour;
            else
                cout<<"No time is set"<<endl;
        }

        int minutes(){
            if(minute!=NULL)
                return minute;
            else
                cout<<"No time is set"<<endl;
        }

        int seconds(){
            if(second!=NULL)
                return second;
            else
                cout<<"No time is set"<<endl;
        }

        void reset(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        }

        void advance(int h,int m, int s){
            second += s;
            if(second>59){
                minute++;
                second = second%60;
            }

            minute += m;
            if(minute>59){
                hour++;
                minute = minute%60;
            }

            hour += h;

            if(hour>23)
                hour = hour%24;
        }

        void print(){
            if(hour!=NULL)
                cout<<hour<<":"<<minute<<":"<<second<<endl;
            else
                cout<<"No time is set"<<endl;
        }
};

//function prototype


int main()
{
    Time sigh;
    sigh.print();

    sigh.reset(22, 53, 21);
    sigh.print();

    sigh.advance(1, 1, 5);
    sigh.print();

    sigh.advance(1, 10, 1);
    sigh.print();

    return 0;
}

//function definition

