// #include <bits/stdc++.h>
// using namespace std;


// int cnt = 5;
// void solve(string &s)
// {   
//     if(cnt == 0) return;
//     cout<<s<<endl;
//     cnt -= 1;
//     solve(s);
   
// }

// int main()
// {   
//     string s;
//     cin>>s;
//     solve(s);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

void solve(int i,int n)
{
    if(i>n) return;         //Base case
    cout<<"Pranith"<<endl;  // calculation work
    solve(i+1,n);           //Recursive approach
}

int main()
{
    int n;
    cin>>n;
    solve(1,n);

    return 0;
}