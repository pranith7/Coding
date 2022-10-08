/*

copy assignment operator is used to set values for an object after it is created 
It is also defined as it is called when an already initialized object is assigned a new value from another existing object
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Product{
    int id;
    char *name;
    int mrp;
    int selling_price;
    public:
        //Constructor
        Product()
        {
            cout<<"Inside the constructor"<<endl;
        }

        //constructor with paramters[Parameterissed constructor]
        Product(int id, char *n,int mrp, int selling_price)
        {   
            // If the variables names are same we use this property 
            // to refer them using this it is a pointer which points for speciferd objects
            this->id = id; // or this->id = id;
            name = new char[strlen(n) + 1];
            strcpy(name,n);
            this->mrp = mrp;
            this->selling_price = selling_price;

        }

        //Copy constructor
        Product (Product &x)
        {   
            // This function used to make our own copy constructor by overwriting the dafult copy constructor
           // default copy constructor basically copies all the values of attributes of a object to a new object.
            id = x.id;
            name = new char[strlen(x.name) + 1];
            strcpy(name,x.name);
            mrp = x.mrp;
            selling_price = x.selling_price + 10;
        }

        //copy assignment operator
        void operator=(Product &x)
        {
            cout<<"Inside the copy constructor"<<endl;
            // Creating a deep copy rather than a shallow copy which default copy assignment operator provides
            id = x.id;
            name = new char[strlen(x.name) + 1];
            strcpy(name,x.name);
            mrp = x.mrp;
            selling_price = x.selling_price;

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
        void setname(char *name)
        {
            strcpy(this->name,name);
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
    Product old_camera;

    old_camera = camera;// --> calling default copy assignment operator 
    old_camera.setname("Uday");
    old_camera.setmrp(4000);

    camera.showdetails();
    old_camera.showdetails();

    // camera.setmrp(100);
    // camera.setsellingprice(90);
    // Product handycam = camera;
    // Product webcam(camera); // Another way to define new object.
    // camera.showdetails();
    // webcam.showdetails();
    // handycam.showdetails();
    // cout<<"Mrp price is "<<camera.getmrp();
    // cout<<endl;
    // cout<<"sellingPrice is"<<camera.getsellingprice();

    return 0;
}