#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> books;
    books.push("C++");
    
    books.push("Python");
    
    books.push("Java");
    while(!books.empty())
    {
        cout<<books.top()<<endl;
        books.pop();
    }
    return 0;
}