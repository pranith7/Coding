#include<bits/stdc++.h>
using namespace std;

bool reverseString(string str,int i,int n)
{
    if(i>=n/2) return true;                  //Base case
    if(str[i]!=str[n-i-1]) return false;    //calculation work
    return reverseString(str,i+1,n);        //recursion approach
}

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    if(reverseString(s,0,n)) 
        cout<<"True";
    else 
        cout<<"False";
}