#include<iostream>
using namespace std;


class Product{
    int id;
    char name[100];
    public:
        int mrp;
        int selling_price;
};

int main()
{
    Product camera;
    
    camera.mrp = 12000;
    cout<<camera.mrp<<endl;

    return 0;
}