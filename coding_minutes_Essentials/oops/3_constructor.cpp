/*
    1. constructor is constructing the object
    2. constructor name = class name
    3. It is calles Automatically when object is created
    4. Memory allocation happens when constructor is called
    5. Constructor is called only once for Each onbject

*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Product{
    int id;
    char name[100];
    int mrp;
    int selling_price;
    public:
        //Constructor
        Product()
        {
            cout<<"Inside the constructor"<<endl;
        }
        //constructor with paramters[Parameterissed constructor]
        Product(int id, char n[],int mrp, int selling_price)
        {   
            // If the variables names are same we use this property 
            // to refer them using this it is a pointer which points for speciferd objects
            this->id = id; // or this->id = id;
            strcpy(name,n);
            this->mrp = mrp;
            this->selling_price = selling_price;

        }
        //setters
        void setmrp(int price)
        {
            mrp = price;
        }
        void setsellingprice(int price)
        {   
            if(price>mrp) selling_price = mrp;
            else selling_price = price;
        }

        //getters
        int getmrp()
        {
            return mrp;
        }
        int getsellingprice()
        {
            return selling_price;
        }

};

int main()
{   
    /*
        constructor overloading is a concept where more than one construcot rexist and it gets called as soon as we created an object from class
        as shown below if we want to call the basic default then we leave like that and if we want to call another constructor then we pass the vlaues 
        to the object
    */
    // Product camera;
    Product camera(45,"pranith", 40,60);
    // camera.setmrp(100);
    // camera.setsellingprice(90);
    cout<<"Mrp price is "<<camera.getmrp();
    cout<<endl;
    cout<<"sellingPrice is"<<camera.getsellingprice();

    return 0;
}