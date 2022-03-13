#include<iostream>
using namespace std;

class Product{
    int id;
    char name[100];
    int mrp;
    int selling_price;
    public:
        void setmrp(int price)
        {
            mrp = price;
        }
        void setsellingprice(int price)
        {   
            if(price>mrp) selling_price = mrp;
            else selling_price = price;
        }
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
    Product camera;
    camera.setmrp(100);
    camera.setsellingprice(90);
    cout<<"Mrp price is "<<camera.getmrp();
    cout<<endl;
    cout<<"sellingPrice is"<<camera.getsellingprice();

    return 0;
}