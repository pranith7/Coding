#include<bits/stdc++.h>
using namespace std;


int compress(vector<char>& chars) {
    // your code goes here
    char count = 0;
    vector<char> alpha;
    for(int i=0;i<=chars.size()-1;i++)
    {   
        if(chars[i]!=chars[i-1])
        {
            if(count!=0)
            {
              alpha.push_back(count);
              count = 0;
            }
            alpha.push_back(chars[i]);
            
        }
        else
        {
            count++;
        }
    }
    
    return alpha.size();
        
}

int main()
{
    int n;
    cin>>n;
    vector<char> chars(n);
    for(int i=0;i<=chars.size()-1;i++)
    {
        cin>>chars[i];
    }
    
    char count;
    count++;
    chars.push_back(count);
    cout<<"output of the chars"<<endl;
    for(int i=0;i<=chars.size()-1;i++)
    {
        cout<<chars[i];
    }
    // cout<<compress(chars);
    return 0;
}