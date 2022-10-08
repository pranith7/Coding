#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    cin.get();
    int count = INT_MIN;
    char sentence[1000];

    char largest[1000];

    while(n--)
    {
        cin.getline(sentence,1000);
        cout<<sentence<<endl;
        int length = strlen(sentence);
        if(length > count)
        {
            strcpy(largest,sentence);
            count = length;
        }
    }

    cout<<"LArgest sentence "<<largest;


}


int main()
{

    solve();
    return 0;
}