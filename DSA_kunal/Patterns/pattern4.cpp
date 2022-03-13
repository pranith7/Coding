#include<bits/stdc++.h>
using namespace std;

int main()
{
   /*   
        1
        1 2
        1 2 3
        1 2 3 4
        1 2 3 4 5
   */

    int n;
    cin>>n;
    for(int rows=1;rows<=n;rows++)
    {
        for(int cols = 1;cols<=rows;cols++)
        {
            cout<<cols<<" ";
        }
        cout<<endl;
    }


    return 0;
}