#include <bits/stdc++.h>
using namespace std;

class RationalNumber    
{
private:
    int num;
    int den;

    void error()
    {
        cout<<"You done messed up!"<<endl;
        num = 0;
        den = 0; //BUT WHY THO?
    }

public:
    RationalNumber(int n, int d): num(n), den(d)
    {};

    RationalNumber(){};
    ~RationalNumber (){};

    void setNum(int n)
    {   
        num = n;
    }

    void setDen(int d)
    {   
        if(d==0){
            error();
            return;
        }
        den = d;
    }

    int getNum()
    {
        return num;
    }

    int getDen()
    {
        return den;
    }

    double toDec()
    {
        if(!den) return (double)num/(double)den;
        error();
    }

    RationalNumber operator + (RationalNumber) const;
    RationalNumber operator - (RationalNumber) const;
    RationalNumber operator * (RationalNumber) const;
    RationalNumber operator / (RationalNumber) const;
    
};

RationalNumber RationalNumber::operator + (RationalNumber frac2) const
{
    return RationalNumber(num * frac2.den + frac2.num * den, den * frac2.den);
}

RationalNumber RationalNumber::operator - (RationalNumber frac2) const
{
    return RationalNumber(num * frac2.den - frac2.num * den, den * frac2.den);
}

RationalNumber RationalNumber::operator * (RationalNumber frac2) const
{
    return RationalNumber(num * frac2.num, den * frac2.den);
}

RationalNumber RationalNumber::operator / (RationalNumber frac2) const
{
    return RationalNumber(num * frac2.den, den * frac2.num);
}


int main()
{   
    RationalNumber sigh;

    int n = 1, d = 2;

    sigh.setDen(d);
    sigh.setNum(n);

    cout<<sigh.getNum()<<" "<<sigh.getDen()<<endl;

    n = 1, d = 2;
    
    RationalNumber sigh2, sigh3;

    sigh3 = sigh + sigh2;

    cout<<sigh3.getNum()<<" "<<sigh3.getDen()<<endl;

    sigh3 = sigh*sigh2;

    cout<<sigh3.getNum()<<" "<<sigh3.getDen()<<endl;

    cout<<sigh3.toDec();

    return 0;
}