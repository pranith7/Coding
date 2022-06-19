#include <bits/stdc++.h>
using namespace std;
#define SIZE 26
 
bool arePermutation(string A, string B)
{
    // your code goes here
    int n = A.length();
    int m = B.length();
    if(n!=m)
    {
       return false;
    } 
    else
    {
        int freq1[SIZE] = {0};
        int freq2[SIZE] = {0};
        for(int i=0;i<n;i++)
        {
            freq1[A[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        { 
            freq2[B[i]-'a']++;       
        }
        for(int i=0;i<26;i++)
        {
            if(freq1[i]!=freq2[i])
            {
                return false;  
            } 
        }
        return true;
    }
    
    
}

int main()
{
    string A,B;
    cin>>A>>B;
    cout<<arePermutation(A,B);
    return 0;
}