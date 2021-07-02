#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    string EMPname;
    int ID;
    int age;
    double salary;

    string getStatus()
    {
        if(age>25)
        {
            if(salary<=21000)   return "Low";
            else if(salary>21000 && salary<=60000)  return "Moderate";
            else if(salary>60000) return "High";
        }
        else
        {
            if(salary<=20000)   return "Low";
            else if(salary>20000)  return "Moderate";
        }
        return "sigh";
    }

public:
    Employee(string name, int id, int Age, double sal): EMPname(name), ID(id), age(Age), salary(sal)
    {};
    ~Employee(){};

    void Feedinfo(string name, int id, int Age, double sal)
    {
        EMPname = name;
        ID = id;
        age = Age;
        salary = sal;
    }

    void showinfo()
    {
        cout<<"Name: "<<EMPname<<endl<<"ID: "<<ID<<endl<<"Salary: "<<salary<<endl<<"Age: "<<age<<endl<<"Status: "<<getStatus()<<" salaried person"<<endl;
    }

};



int main()
{
    Employee sigh("Patrick", 101, 26, 70000);

    sigh.showinfo();

    return 0;
}
