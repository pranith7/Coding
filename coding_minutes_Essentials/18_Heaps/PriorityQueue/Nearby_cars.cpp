#include<bits/stdc++.h>
using namespace std;

class Car{

public:
    string id;
    int x,y;
    Car(string id,int x,int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist() const
    {
        return x*x + y*y;
    }

};

class CarCompare
{   
public:
    bool  operator()(const Car A,const Car B) 
    {
        return A.dist() < B.dist(); //MAx Heap
    }  
};

void printNearsetCars(vector<Car> cars,int k)
{   
    
}

int main()
{
    int N,K;
    cin>>N>>K;
    string id;
    int x,y;
    vector<Car> cars(N+1);
    for(int i=0;i<N;i++)
    {
        cin>>id>>x>>y;
        Car car(id,x,y);
        cars.push_back(car);
    }
    printNearsetCars(cars,K);

    return 0;
}