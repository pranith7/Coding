#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin>>n;

    string s;
    s = to_string(n);

    for(int i=0;i<s.length();i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}