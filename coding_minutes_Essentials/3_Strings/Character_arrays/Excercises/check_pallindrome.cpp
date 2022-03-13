#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    // your code goes here
    int n = str.length();
    for(int i=0;i<str.length()-1;i++)
    {
        if(str[i]!=str[n-1])
        {
           return false;   
        }
        n--;
    }
    
    return true;
}