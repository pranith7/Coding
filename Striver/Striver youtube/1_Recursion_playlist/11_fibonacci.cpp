#include<bits/stdc++.h>
using namespace std;


int first;
int second;
int fibonacci(int n)
{
    if(n == 0)
        return 0; // Base case
    if(n == 1)
        return 1;

    first = fibonacci(n-1);
    second = fibonacci(n-2); //Calculation of fibonacci number

    return first + second; //recursive approach
}

int main()
{
    int n;
    cin>>n;
    cout<<fibonacci(n);

    return 0;
}