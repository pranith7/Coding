/*

copy constructor is creating another copy of object using the object which already declared.

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

            //Copy constructor
        Product (Product &x)
        {   
            // This function used to make our own copy constructor by ocerwriting the dafult copy constructor
           // default copy constructor basically copies all the values of attributes of a object to a new object.
            id = x.id;
            mrp = x.mrp;
            selling_price = x.selling_price + 10;
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
        void showdetails()
        {
            cout<<"Name is"<<name<<endl;
            cout<<"ID is "<<id<<endl;
            cout<<" Mrp price is"<<mrp<<endl;
            cout<<"selling price is "<<selling_price<<endl;
            cout<<"_______________"<<endl;

        }

};

int main()
{   
    // Product camera;
    Product camera(45,"pranith", 40,35);
    // camera.setmrp(100);
    // camera.setsellingprice(90);
    Product handycam = camera;
    Product webcam(camera); // Another way to define new object.
    camera.showdetails();
    webcam.showdetails();
    handycam.showdetails();
    // cout<<"Mrp price is "<<camera.getmrp();
    // cout<<endl;
    // cout<<"sellingPrice is"<<camera.getsellingprice();

    return 0;
}