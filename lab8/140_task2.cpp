#include <bits/stdc++.h>
using namespace std;

class Seat
{
    protected:
        string comfy;
        bool hasSeatWarmer;
    
    public:
        Seat()
        {}
        Seat(string com, bool has) : comfy(com), hasSeatWarmer(has)
        {}
    
        void putComfy(string com)
        {
            comfy = com;
        } 
        void putSeatWarmer(bool has)
        {
            hasSeatWarmer = has;
        }
    
        string showComfy() const
        {
            return comfy;
        }
        bool seatWarmerStatus() const
        {
            return hasSeatWarmer;
        }
};

class Wheel
{
    protected:
        double circumference;
 
    public:
        Wheel()
        {}
        Wheel(double c) : circumference(c)  
        {}
    
        void set_circum(double c)
        {
            circumference = c;
        }
        
        double get_circum() const
        {
            return circumference;
        }
};

class Engine
{
    protected:
        double max_fuel_consumption_rate;
        double max_energy_production_rate;
        double avg_RPM;
 
    public:
        Engine()
        {}
        Engine(double max_fuel, double max_energy, int rpm) : max_fuel_consumption_rate(max_fuel), max_energy_production_rate(max_energy),avg_RPM(rpm)
        {}
    
        void set_max_fuel(double max_fuel)
        {
            max_fuel_consumption_rate = max_fuel;
        }
        void set_max_energy(double max_energy)
        {
            max_energy_production_rate = max_energy;
        }
        void set_avg_RPM(double rpm)
        {
            avg_RPM = rpm;
        }
    
        double get_max_fuel() const
        {
            return max_fuel_consumption_rate;
        }
        double get_max_energy() const
        {
            return max_energy_production_rate;
        }
        int get_avg_RPM() const
        {
            return avg_RPM;
        }
};

class Door
{
    protected:
        string opening_mode;
 
    public:
        Door()
        {}
        Door(string mode): opening_mode(mode)
        {}
    
        void set_mode(string mode)
        {
            opening_mode = mode;
        }
        
        string get_mode() const
        {
            return opening_mode;
        }
};

class Car: public Seat, public Wheel, public Engine, public Door
{
    private:
        double max_acceleration;
        double fuel_capacity;
 
    public:
        Car(): Seat(), Wheel(), Engine(), Door()
        {}
        Car(double max_a, double fuel): Seat(), Wheel(), Engine(), Door(), max_acceleration(max_a), fuel_capacity(fuel)
        {}
        Car(double max_acc, double fuel,string com, bool hasWarmer, double circum, double max_fuel, double max_energy, int rpm, string mode):
                Seat(com, hasWarmer), Wheel(circum), Engine(max_fuel, max_energy, rpm), Door(mode), max_acceleration(max_acc), fuel_capacity(fuel)
        {}
    
        void set_maximum_acceleration(double max_a)
        {
            max_acceleration = max_a;
        }
        void set_fuel_capacity(double fuel)
        {
            fuel_capacity = fuel;
        }
    
        double get_maximum_acceleration() const
        {
            return max_acceleration;
        }
        double get_fuel_capacity() const
        {
            return fuel_capacity;
        }
    
        void display() const
        {
            cout << "Maximum Acceleration: " << get_maximum_acceleration() << endl
                << "Fuel Capacity: " << get_fuel_capacity() << endl
                << "Seat Comfortability: " << showComfy() << endl
                << "Seat Warmer: " << seatWarmerStatus() << endl
                << "Wheel Circumference: " << get_circum() << endl
                << "Maximum Fuel Consumption Rate: " << get_max_fuel() << endl
                << "Maximum Energy Production Rate: " << get_max_energy() << endl
                << "Average RPM: " << get_avg_RPM() << endl
                << "Door Opening Mode: " << get_mode() << endl;
        }
};

int main()
{

    Car choleNa(16, 500, "Uncomfortable", false, 17.7, 700.71, 500.45, 576, "Doesn't open");
    
    cout<<endl;
    choleNa.display();
    cout<<endl;

    return 0;
}