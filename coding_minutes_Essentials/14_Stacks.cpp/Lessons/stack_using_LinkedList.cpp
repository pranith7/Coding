#include<bits/stdc++.h>
#include "stackLL.h"
using namespace std;

int main()
{

    Stack<char> s;
    s.push('h');
    s.push('e');
    s.push('i'); 
    s.push('o');
    s.push('u');
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}