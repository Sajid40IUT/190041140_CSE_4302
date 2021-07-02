#include <bits/stdc++.h>
using namespace std;

class StudentResult
{
private:
    static int passingMark;
    int subjectMark[6];
    bool fail;
public:
    StudentResult(): fail(0)
    {};
    ~StudentResult(){};

    void setMarks(int m1, int m2, int m3, int m4, int m5, int m6)
    {
        subjectMark[0] = m1;
        subjectMark[1] = m2;
        subjectMark[2] = m3;
        subjectMark[3] = m4;
        subjectMark[4] = m5;
        subjectMark[5] = m6;
    }

    void displayMarks()
    {
        for (int i = 0; i < 6; i++)
        {
            cout<<"Subject "<<i+1<<": "<<subjectMark[i]<<endl;
        }   
    }

    void checkPassing()
    {
        for (int  i = 0; i < 6; i++)
        {
            if(subjectMark[i]<passingMark)
            {
                fail = 1;
                break;
            }
        }

        if(fail) cout<<"Failed!"<<endl;
        else cout<<"Passed!"<<endl;
        
    }


};

int StudentResult::passingMark = 50;

int main()
{   
    StudentResult sigh;

    sigh.setMarks(60, 60, 40, 55, 70, 60);
    sigh.checkPassing();
    sigh.displayMarks();

    return 0;
}