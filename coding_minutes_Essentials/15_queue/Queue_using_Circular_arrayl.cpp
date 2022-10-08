#include<bits/stdc++.h>
#include "queue.h"
using namespace std;

int main()
{
    Queue myq(7);
    myq.push(1);
    myq.push(2);
    myq.push(3);
    myq.push(4);
    myq.push(5);
    myq.push(6);
    myq.push(7);
    myq.push(8);
    myq.pop();
    myq.pop();
    myq.push(9);

    while(!myq.empty())
    {
        cout<<myq.getFront()<<" ";
        myq.pop();
    }
    
    
    return 0;
}