#include <bits/stdc++.h>
using namespace std;

class Animal
{
private:
    string nameOfAnimal;
    string habitat_area;
    string sound;
    int weight;
    int height;
    int birthYear;
public:
    Animal(): birthYear(2021)
    { }
    Animal(string name, string area, string s, int w, int h, int y): nameOfAnimal(name), habitat_area(area), sound(s), weight(w), height(h), birthYear(y)
    {
        if(birthYear>2021)
            cout<<"Invalid Birthyear, reasigning to 2021"<<endl;
        
        birthYear = 2021;
    }

    Animal(string s): sound(s), birthYear(2021)     //one argument constructor so that we can set the sounds of the subclasses as we create objects 
    { }

    void set_name(string name)
    {
        nameOfAnimal = name;
    }
    void set_habitat(string area)
    {
        habitat_area = area;
    }
    void set_sound(string s)
    {
        sound = s;
    }
    void set_weight(int w)
    {
        weight = w;
    }
    void set_height(int h)
    {
        height = h;
    }
    void set_birthYear(int year)
    {   
        birthYear = year;

        if(birthYear>2021)
        {
            cout<<"Invalid Birthyear, reasigning to 2021"<<endl;
            birthYear = 2021 ;
        }    

    }

    string get_name() const
    {
        return nameOfAnimal;
    }
    string get_habitat() const
    {
        return habitat_area;
    }
    string get_sound() const
    {
        return sound;
    }
    int get_weight() const
    {
        return weight;
    }
    int get_height() const
    {
        return height;
    }
    int get_age() const
    {
        return 2021 - birthYear;
    }

    void getInformation() const
    {
        cout << "Name: " << nameOfAnimal <<endl<< "Habitat Area: " << habitat_area << endl<< "Sound: " << sound <<endl<< "Weight: " << weight <<endl<< "Height: " << height << endl<< "Birth Year: " << birthYear << endl<< "Age: " << get_age() << endl;
    }

    void changeWeight(int pounds)
    {
        weight = pounds;
    }
 
    void vocalize() const
    {
        cout << sound;
    }

};

class Cow : public Animal
{   
    public:
        Cow(): Animal("moo")
        { }
        Cow(string name, string area, string s, int w, int h, int year): Animal(name, area, s, w, h, year)
        { }
};


class Chicken : public Animal
{
    public:
        Chicken(): Animal("buck buck")
        { }
        Chicken(string name, string area, string s, int w, int h, int year): Animal(name, area, s, w, h, year)
        { }
};


class Cat : public Animal
{
    public:
        Cat(): Animal("meow")
        { }
        Cat(string name, string area, string s, int w, int h, int year): Animal(name, area, s, w, h, year)
        { }
};

int main()
{

    Cow Hamba;
    Chicken chick;
    Cat neko;


    Hamba.getInformation();
    cout<<endl;

    chick.getInformation();
    cout<<endl;

    neko.getInformation();
    cout<<endl;

    return 0;
}