#include<iostream>
#include<cstring>
using namespace std;

int main()
{   
    char a[] = {'a','b','c','d','e','\0'}; // "abc"
    cout<<a<<endl;
    char b[100];
    cin>>b;

    cout<<b<<endl;

    cout<<sizeof(a)<<endl;  // +1 because of the null at end
    cout<<strlen(a)<<endl; // Number of Characters in a character array

    return 0;
}