#include<bits/stdc++.h>
using namespace std;

void solve(int &income)// Pass by reference using reference variable
{
    float tax = 0.10;
    income = income - income*tax;
}
 

void solve1(int *viewsptr)// Pass by refernce using pointers 
{
    *viewsptr = *viewsptr + 1;
}

int main()
{   
    /*
        It has two ways using 
            1. Pointer
            2. using Reference Variable
               int x = 10;
                int &y = x;
                y++;
                x++;
                cout<<x<<endl;
                cout<<y<<endl;
    */
    int income;
    cin>>income;

    int views = 100;
    // solve(income);
    solve1(&views);
    cout<<views<<endl;
    // cout<<income;
    return 0;
}