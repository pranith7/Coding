#include<bits/stdc++.h>
using namespace std;


int main()
{   
    char sentence[10000];
    char temp = cin.get();

    // int length = 0;
    // while(temp!='\n')
    // {   
    //     length++;
    //     cout<<temp;
    //     temp = cin.get();
    // }

    // cout<<"Length "<<length;

    int length = 0;
    while(temp!='#')
    {   
        
        sentence[length++] = temp;
        temp = cin.get();
    }
    sentence[length] = '\0';
    cout<<"Length "<<length<<endl;
    cout<<"Sentence "<<sentence<<endl;


    return 0;
}
