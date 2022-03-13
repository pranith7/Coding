#include<bits/stdc++.h>
using namespace std;


int main()
{

    char a[1000] = "apple";
    char b[1000];

    cout<<strlen(a)<<endl;

    strcpy(b,a);//Destination,source

    cout<<strcmp(a,b);//returns 0 if it is same and 1 or -1 of it doesnt

    strcat(a,b);


    return 0;
}