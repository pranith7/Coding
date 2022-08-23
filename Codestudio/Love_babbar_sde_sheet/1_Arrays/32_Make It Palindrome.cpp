#include<bits/stdc++.h>
using namespace std;

int palindrome(vector<int> A)
{
    int n = A.size();
    int i = 0;
    int j = n - 1;
    int ans = 0;
    
    long long left = A[0], right = A[n - 1];
    
    while(i < j) {
        if(left == right) {
            i++;
            j--;
            left = A[i];
            right = A[j];
        }
        else if(left < right) {
            ans++;
            left = left + A[i + 1];
            i++;
        }
        else {
            ans++;
            right = right + A[j - 1];
            j--;
        }
    }
    return ans;
}


int main()
{
    int n;
    cin>>n;

    vector<int> A(n);
    for(int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    cout<<palindrome(A)<<endl;
    return 0;
}