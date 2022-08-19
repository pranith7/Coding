#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
   unordered_set<int> s;
   for(int i=0;i<n;i++)
   {
        s.insert(arr[i]);
   }
   int longstreak = 0;
   for(int i=0;i<n;i++)
   {
        if(s.find(arr[i]-1)==s.end())
        {
            int CurrentElement = arr[i];
            int CurrentStreak = 0;
            while(s.find(CurrentElement)!=s.end())
            {
                CurrentStreak++;
                CurrentElement++;
            }
            longstreak = max(CurrentStreak,longstreak);
        }
        
       }    
       return longstreak;
    
}

int main()
{

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<lengthOfLongestConsecutiveSequence(arr,n);
    return 0;
}