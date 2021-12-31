#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int nor;
    cin>>nor;
    
    int nos = nor/2;
    int nost = 1;


    for(int cr = 1;cr<=nor;cr++)
    {
        for(int csp = 1;csp<=nos;csp++)
        {
            cout<<"\t";
        }
        for(int cst = 1;cst<=nost;cst++)
        {
            cout<<"*\t";
        }

        if(cr<= nor/2)
        {   
            nos--;
            nost = nost + 2;
        }
        else
        {
            nos++;
            nost = nost - 2;
        }
        cout<<endl;
    }
    return 0;
}