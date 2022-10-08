#include<bits/stdc++.h>
using namespace std;

string vowel(string S)
{
    // your code goes here
    string str;
    for(int i=0;i<S.length();i++)
    {
        if(S[i] == 'a' or S[i] == 'e' or S[i] == 'i' or S[i] == 'o' or S[i] == 'u')
            str.push_back(S[i]);
    }    
    return str;
} 

int main()
{
    string s;
    cin>>s;
    cout<<vowel(s)<<endl;
    return 0;
}