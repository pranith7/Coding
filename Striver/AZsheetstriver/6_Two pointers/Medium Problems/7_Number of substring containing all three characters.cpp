#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> map(3,0);
        int counter = 0 , ans = 0 , i = 0 , j = 0 ;
       while(j<s.size())
        {
          if(map[s[j++] - 'a']++ == 0) counter++;   
           while(counter == 3)
           {
               ans += s.size() - j +1;
               if(map[s[i++] -'a']-- == 1) counter--;
           }
        }
        return ans;
    }
};