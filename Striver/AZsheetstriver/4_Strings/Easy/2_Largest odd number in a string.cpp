#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.length() - 1; i >= 0; --i)
		if(int(num[i]) % 2)
			return num.substr(0, i + 1);

	return "";
    }
};

int main()
{
    string num,res;
    cin>>num;
    Solution ob;
    res = ob.largestOddNumber(num);
    cout<<res;

    return 0;
}