#include<bits/stdc++.h>
using namespace std;

int main()
{
   /*   
        *
       **
      ***
      ****
     *****
      ****
       ***
       **
        *
   */

    int n;
    cin>>n;
    for(int rows=1;rows<=2*n-1;rows++)
    {   
        int totalcols = rows > n ? 2*n - rows : rows;
        int noofspaces = n - totalcols;
        for(int s = 1;s<=noofspaces;s++)
        {
            cout<<" ";
        }
        for(int cols = 1;cols<=totalcols;cols++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}