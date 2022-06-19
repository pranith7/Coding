#include<bits/stdc++.h>
using namespace std;


int compress(vector<char> &chars)
 {
    // your code goes here
    int count_ = 1;
    string alpha;
    for(int i=0;i<=chars.size()-1;i++)
    {   
        if(chars[i]!=chars[i+1])
        {
            if(count_!=1)
            {   
              alpha += to_string(count_);
              alpha += (chars[i]);
              count_ = 1;
            }
            
        }
        else
        {
            count_++;
        }
    }
    
    return alpha.size();
    // int count_=1;
    // string ans;
	
    // for(int i=0;i<chars.size();i++)
    // {
    //     while(i<chars.size()-1 && chars[i+1] == chars[i])
    //     {
    //         count_++;
    //         i++;
    //     }
    //     ans += chars[i];
    //     if(count_ == 1)
    //     {
    //         continue;
    //     }
    //     ans += to_string(count_);
    //     count_ = 1;
    // }
    
    //  chars.clear();
    
    //  for(int i=0;i<ans.size();i++)
    //  {
    //       chars.push_back(ans[i]);
    //  } 
 
    // return ans.size();
        
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
    
    // char count;
    // count++;
    // chars.push_back(count);
    // cout<<"output of the chars"<<endl;
    // for(int i=0;i<=chars.size()-1;i++)
    // {
    //     cout<<chars[i];
    // }
    cout<<compress(chars);
    return 0;
}