#include <iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;
 
int binaryToDecimal(string s)
{
    // your code goes here
    int count = 0;
    int var;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i] == '1')
        {
          var = pow(2,s.length()-1-i);   
        }
        count += var;
        var = 0;
    }
    return count;
}


 
int main()
{
    string s;
    cin>>s;

    cout<<binaryToDecimal(s);
    return 0;
}