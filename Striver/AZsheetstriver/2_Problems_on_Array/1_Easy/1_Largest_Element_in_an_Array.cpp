#include<bits/stdc++.h>
using namespace std;

int Largest_Element(vector<int> arr)
{   
    int max_element = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] > max_element)
        	max_element = arr[i];
    }

    return max_element;
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
    cout<<"Answer is"<<endl;
    int ans = Largest_Element(arr);
    cout<<ans<<endl;
    return 0;
}