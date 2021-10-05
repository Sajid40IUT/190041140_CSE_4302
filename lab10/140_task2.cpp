#include <bits/stdc++.h>
using namespace std;

class player
{
    private:
        string name;
        int lvl;
        string weapon;

        /*
        player(player& p):weapon("Axe") //Copy Initialization
        {
            weapon = p.weapon;
        }

        player operator = (const player& p) //Assignment Operator
        {
            weapon = p.weapon;
            return *this;
        }
        */

    public:
        player()
        {}

        player(string n, int l, string w): name(n), lvl(l), weapon(w)
        {}

        
        player(player& p):weapon("Axe") //Copy Initialization
        {
            weapon = p.weapon;
        }

        player operator = (const player& p) //Assignment Operator
        {
            weapon = p.weapon;
            return *this;
        }
        

        void get_info()
        {
            cout << "Enter Name: "; cin >> name; cout << endl;
            cout << "Enter Lvl: ";  cin >> lvl; cout << endl;
            cout << "Enter Weapon: ";  cin >> weapon; cout << endl;
        }
        
        void show_info()
        {
            cout << "Enter Name: " << name << endl;
            cout << "Enter Lvl: " << lvl << endl;
            cout << "Enter Weapon: " << weapon << endl;
        }

};


int main()
{

    player p1, p2("Litt", 100, "dagger");

    p1.get_info();

    p1.show_info();
    cout << endl;
    p2.show_info();

    p1 = p2;    //copy

    cout << endl;
    p1.show_info();

    player p3 = p2; //assignment

    cout << endl;
    p3.show_info();

    return 0;
}