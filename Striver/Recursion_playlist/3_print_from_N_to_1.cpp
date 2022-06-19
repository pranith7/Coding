// #include<bits/stdc++.h>
// using namespace std;


// int x = 0;

// void solve(int num)
// {
//     if(x == num) return;  //Base case
//     x++;
//     solve(num);           //Recursive approach
//     cout<<x--<<endl;      //calculation work
// }


// int main()
// {   

//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int num;
//         cin>>num;
//         solve(num);
//     }
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

void solve(int i,int n)
{
    if(i<1) return;         //Base case
    cout<<i<<endl;          // calculation work
    solve(i-1,n);           //Recursive approach
   
}

int main()
{
    int n;
    cin>>n;
    solve(n,n);

    return 0;
}