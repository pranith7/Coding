#include<bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------------

Subsequence of a string or array is a contingous or non contigous sequence 
which follows the order of the array or string 

*/
void subsequence(int i,vector<int> &temp,int n,int arr[])
{
    if(i == n)  // Base condition
    {
        for(int i = 0; i < temp.size(); i++)
            cout<<temp[i]<<" ";
            
        if(temp.size() == 0)    
            cout<<"{}";
        cout<<endl;
        return;
    }
    
    temp.push_back(arr[i]); 
    subsequence(i+1,temp,n,arr);
    temp.pop_back();
    subsequence(i+1,temp,n,arr);

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> temp;

    cout<<"The subsequences are as follows"<<endl;
    subsequence(0,temp,n,arr);
    return 0;
}