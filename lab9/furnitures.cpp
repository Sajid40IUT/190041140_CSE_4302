#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood, Board, Steel, foam};

class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string productName;
public:

    Furniture()
    {}

    Furniture(double p,double d,Material m, string name):price(0),discount(0),madeof(Material::Wood), productName("")
    {
        setPrice(p);
        setDiscount(d);
        setProductName(name);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount = val;
    }
    void setProductName(string name)
    {
        productName = name;
    }
    void setMadeof(Material val)
    {
        madeof = val;
    }
    double getDiscountedPrice()
    {
        return price - discount;
    }
    void setDiscountPercentage(double val)
    {
        if(val > 0)
            discount = val/100 * price;
    }
    string getMadeof()
    {
        if(madeof == Material::Wood)
            return string("Wood");
        else if(madeof == Material::Board)
            return string("Board");
        else if(madeof == Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails()=0;
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{   
    BedSize bsize;

    public:
        Bed(double p = 0,double d = 0,Material m = Material::Wood, BedSize b = BedSize::Single)
        {
            setPrice(p);
            setDiscount(d);
            setMadeof(m);
            bsize = b;   
        }

        string getBedSize()
        {
            if (bsize == BedSize::Single)
                return "Single";
            if (bsize == BedSize::SemiDouble)
                return "Semidouble";
            if (bsize == BedSize::Double)
                return "Double";
        }

        void productDetails()
        {   
            cout << string(20, '-') << '\n';
            cout << "Product Name:" << productName << '\n';
            cout << "Regular Price: " << price << '\n';
            cout << "Discounted Price: " << price - discount << '\n';
            cout << "Material: " << getMadeof() << '\n';
            cout << "Bed Size: " << getBedSize() << '\n';
            cout << string(20, '#') << '\n';
        }
};

enum class SeatNumber {One, Two, Three, Four, Five};

class Sofa:public Furniture
{       
    private:
        SeatNumber snumber;
    
    public:
        Sofa(double p = 0, double d = 0, Material m = Material::Wood, SeatNumber s = SeatNumber::One)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        snumber = s;
    }

    string getSeatNumber()
    {
        if (snumber == SeatNumber::One)
            return "One";
        if (snumber == SeatNumber::Two)
            return "Two";
        if (snumber == SeatNumber::Three)
            return "Three";
        if (snumber == SeatNumber::Four)
            return "Four";
        if (snumber == SeatNumber::Five)
            return "Five";
    }

    void productDetails()
    {
        cout << string(20, '-') << '\n';
        cout << "Product Name: " << productName << '\n';
        cout << "Regular Price: " << price << '\n';
        cout << "Discounted Price: " << price - discount << '\n';
        cout << "Material: " << getMadeof() << '\n';
        cout << "Seat Number: " << getSeatNumber() << '\n';
        cout << string(20, '#') << '\n';
    }


};

enum class ChairCount {Two, Four, Six};

class DiningTable:public Furniture
{

    private:
    ChairCount chaircount;
    
    public:
    DiningTable(double p = 0, double d = 0, Material m = Material::Wood, ChairCount c = ChairCount::Two)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        chaircount = c;
    }

    string getChairCount()
    {
        if (chaircount == ChairCount::Two)
            return "Two";
        if (chaircount == ChairCount::Four)
            return "Four";
        if (chaircount == ChairCount::Six)
            return "Six";
    }

    void productDetails()
    {
        cout << string(20, '-') << '\n';
        cout << "Product Name: " << productName << '\n';
        cout << "Regular Price: " << price << '\n';
        cout << "Discounted Price: " << price - discount << '\n';
        cout << "Material: " << getMadeof() << '\n';
        cout << "Chair Count: " << getChairCount() << '\n';
        cout << string(20, '#') << '\n';
    }

};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/

void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures)
{
    for (int i = 0; i < no_of_furnitures; i++)
    {
        for (int j = i + 1; j < no_of_furnitures; j++)
        {
            if (furnitures[i] ->getDiscountedPrice() < furnitures[j] ->getDiscountedPrice())
            {
                Furniture *temp = furnitures[i];
                furnitures[i] = furnitures[j];
                furnitures[j] = temp;
            }
        }
    }
}

int main()
{
    Furniture* f_list[100];

    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SeatNumber::Five);
    f_list[2] = new Sofa(15300,700,Material::Board,SeatNumber::Two);
    f_list[3] = new DiningTable(10090,123,Material::Wood,ChairCount::Six);
    
    f_list[0]->setProductName("Master Bed");
    f_list[3]->setProductName("Hall Table");

    for (int i = 0; i < 4; i ++)
        f_list[i]->productDetails();
    
    f_list[2]->setDiscount(30);
    
    cout << endl << endl << endl;

    for(int i = 0; i < 4; i++)
        f_list[i]->productDetails();
    
    
    //f_list[0]->productDetails();
    
    cout << endl << endl << endl << "Sorted by discount:" << endl ;

    sort_furniture_discount(f_list,4);
    for (int i = 0; i < 4; i++)
        f_list[i]->productDetails();
   
    return 0;
}
