//if n=4
// it should print the following diagram
/*

****
***
**
*

*/

#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{
    //Base case
    if(n==0) return; 
    //Recursive Assumption
    for(int i=0;i<n;i++)
    {
        cout<<"* ";
    }
    cout<<endl;
    //Self work
    solve(n-1);
}
//without using the loop
/*(n,i)->wherre n is the row and i is 0
Base case
if(n==0) return;
//recursive assumption
if(i<n)
{
    cout<<"* ";-->self work
    solve(n,i+1);--> recursion
}
else
{   
    cout<<endl;--> self work
    solve(n-1),i);--> recursion
}

*/

int main()
{
    solve(4);

    return 0;
}