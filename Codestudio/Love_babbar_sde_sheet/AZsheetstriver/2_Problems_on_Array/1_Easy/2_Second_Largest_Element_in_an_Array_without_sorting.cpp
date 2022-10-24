#include<bits/stdc++.h>
using namespace std;

int Second_Largest(vector<int> arr)
{
    int Largest = arr[0];
    int Second_Largest = -1;
    for(int i = 0; i < arr.size();i++)
    {
        if(arr[i] > Largest)
        {
            Second_Largest = Largest;
            Largest = arr[i];
        }
         if(arr[i]!= Largest)
            Second_Largest = max(Second_Largest,arr[i]);
    }

    return Second_Largest;
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
    int ans = Second_Largest(arr);
    cout<<ans<<endl;
    return 0;
}