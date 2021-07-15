#include <bits/stdc++.h>
using namespace std;

class Counter
{
private:
    unsigned int count;
    int incremt;
public:
    Counter():  count(0), incremt(1)
    {};
    Counter(int c): count(c), incremt(1)
    {};
    ~Counter()
    {};

    void setIncrementStep(int step_val)
    {   
        if(step_val<1)
        {
            cout<<"invalid input. Set to default";
            return;
        }

        incremt = step_val;
    }

    int getCount()
    {
        return count;
    }

    void increment()
    {
        count+=incremt;
    }

    void resetCount()
    {
        count = 0;
    }

    Counter operator + (Counter cx)
    {
        Counter temp;
        temp.count = count + cx.count;
        
        return temp;
    }

    Counter operator + (int val)
    {
        Counter temp;
        temp.count = count + val;
        
        return temp;
    }

    friend Counter operator + (int val, Counter &right)
    {
        return Counter(val + right.count);
    }

    Counter operator ++ ()
    {
    return Counter(++count); 
    }
    Counter operator ++ (int) 
    { 
    return Counter(count++);
    }

    void operator += (Counter cx)
    {
        count += cx.count;
    }

};

int main()
{
    Counter c1,c2,c3(3);

    cout<<c1.getCount()<<' '<<c2.getCount()<<' '<<c3.getCount()<<endl;

    c1 += c3;

    //cout<<c1.getCount();

    int val=5;

    c1 = val + c2;

    //cout<<c1.getCount();

    c1++;
    ++c1;

    //cout<<c1.getCount();


    return 0;
}