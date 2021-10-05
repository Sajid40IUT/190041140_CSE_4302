#include <bits/stdc++.h>
using namespace std;

class hotel
{
    protected:
        string employee_name;
        int age;
        string company;
        string position;
        string workplace;

    public:
        hotel()
        {}

        hotel(string name, int old): employee_name(name), age(old)
        {}

        ~hotel()
        {};

        void get_info()
        {   
            cout << "Enter Employee Name: "; cin >> employee_name;
            cout << "Enter Employee Age: "; cin >> age;
            cout << "Enter Company Name: "; cin >> employee_name;
            cout << "Enter Employee Position: "; cin >> position;
            cout << "Enter Place of Work: "; cin >> workplace;
        }

        virtual void show_info()
        {
            cout << "I am an Employee at " << company << " Hotel";
        }

        virtual void employee_satisfaction() = 0;

};

class HR : public hotel
{
    protected:
    
    public:

        void show_info()
        {
            cout << "Name: " << employee_name << endl 
                << "Age: " << age << endl
                << "Company Name: " << company << endl
                << "Position: " << position << endl
                << "Posted at: " << workplace << endl;
        }

        void employee_satisfaction()
        {
            cout << endl << "Employee Satisfaction: Satisfied" << endl;
        }

};

class cleaning : public hotel
{
    protected:

    public:
        //void show_info will use the default definition

        void employee_satisfaction()
        {
            cout << endl << "Employee Satisfaction: Unsatisfied" << endl;
        }

};

int main()
{
    HR h;
    cleaning c;

    hotel *employee1 = &h;
    hotel *employee2 = &c;

    employee1->get_info();
    employee1->show_info();
    employee1->employee_satisfaction();

    cout << endl;

    employee2->get_info();
    employee2->show_info();
    employee2->employee_satisfaction();

    return 0;
}