#include<bits/stdc++.h>
using namespace std;

int main()
{

    char ch;
    ch = cin.get();

    int alpha = 0;
    int numeric = 0;
    int spaces = 0;

    while(ch!='\n')
    {
        if(ch>='0' and ch<='9') numeric++;
        if (ch == ' ' and ch == '\t') spaces++;
        if((ch>='a' and ch <= 'z') or (ch >= 'A' and ch<='Z')) alpha++;
        ch = cin.get();
    }
    cout<<"alpha "<<alpha<<" "<<"numeric "<<numeric<<" "<<"spaces "<<spaces<<endl;

    return 0;
}