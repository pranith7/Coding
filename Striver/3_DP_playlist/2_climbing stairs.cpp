/*

Shortcut:-
1. Try to represent the problem in terms of index
2. Do all possible tuffs on that index according to the problem statement
3. Sum of all stuffs -> count all ways
   min(of all stuffs) -> find min

*/
#include<bits/stdc++.h>
using namespace std;

int stairs(int idx)
{
    if(idx == 0) return 1;
    if(idx == 1) return 1;

    int left = stairs(idx - 1);
    int right = stairs(idx-2);

    return left + right;
}

int main()
{
    int n;
    cin>>n;
    cout<<stairs(n);
    return 0;
}