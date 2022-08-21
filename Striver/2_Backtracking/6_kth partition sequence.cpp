#include<bits/stdc++.h>
using namespace std;

string solve(int n,int k)
{
    int fact = 1;
    vector<int> numbers;
    for(int i=1;i<n;i++)
    {
        fact = fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k-1;
    while(true)
    {
        ans = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0) break;
        k %= fact;
        fact /= numbers.size(); 
    }

    return ans;

}

int main()
{
    int n,k;
    cin>>n>>k;
    string ans;
    ans = solve(n,k);
    cout<<ans<<endl;
    return 0;
}