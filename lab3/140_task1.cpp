#include <bits/stdc++.h>
using namespace std;

class RationalNumber{
    private:
        int numerator;
        int denominator;

    public:
        void assign(int numerator, int denominator){

            this->numerator = numerator;

            if(denominator!=0)
                this->denominator = denominator;
            else
                cout<<"Error: undefined value."<<endl;
        }

        double convert(){
            return double(numerator)/double(denominator);
        }

        void invert(){
            if(numerator==0)
                cout<<"Error: cannot be inverted"<<endl;
            else{
                swap(numerator, denominator);
            }

        }

        void print(){
            cout<<"The rational number is "<<numerator<<'/'<<denominator<<endl;
        }
};

//function prototype


int main()
{
    RationalNumber sigh;

    sigh.assign(2,3);
    sigh.print();

    cout<<sigh.convert()<<endl;

    sigh.invert();

    cout<<sigh.convert()<<endl;

    sigh.print();

    return 0;
}

//function definition

