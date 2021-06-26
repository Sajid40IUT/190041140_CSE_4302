#include <bits/stdc++.h>
using namespace std;

class Medicine{
    private:
        string name;
        string genericName;
        double discountPercent = 5.f;
        double unitPrice = 0.2f;

    public:
        void assignName(string name, string genericName){
            this->name = name;
            this->genericName = genericName;
        }

        void assignPrice(double price){
            if(price>=0)
                unitPrice = price;
            else
                cout<<"Error: Invalid price input"<<endl;
        }

        void setDiscountPercent(double percent){
            if(percent>=0 && percent<=45)
                discountPercent = percent;
            else
                cout<<"Error: Invalid percent input"<<endl;
        }

        double getSellingPrice(int nos){
            double unit;

            unit = unitPrice - (unitPrice*(discountPercent/100));

            return unit*double(nos);
        }

        void display(){
            cout<<genericName<<" ("<<name<<") has a unit price of BDT "<<unitPrice<<". Current discount "<<discountPercent<<"%.";
        }
};

//function prototype


int main()
{
    Medicine sigh2;

    sigh2.assignName("Paracetamol", "Napa");
    sigh2.assignPrice(0.80f);
    sigh2.setDiscountPercent(10.f);
    //cout << sigh2.getSellingPrice(1) << '\n';
    sigh2.display();

    return 0;
}

//function definition

