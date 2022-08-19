#include<bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------------

Subsequence of a string or array is a contingous or non contigous sequence 
which follows the order of the array or string 

*/
void subsequence(int i,vector<int> &temp,int n,int arr[],int s,int sum)
{
    if(i == n) 
    {   
        if(s == sum) // check the condition
        {
            for(int j = 0;j < temp.size();j++)
            {
                cout<<temp[j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    temp.push_back(arr[i]);
    s = s + arr[i]; 
    subsequence(i+1,temp,n,arr,s,sum);
    temp.pop_back();
    s -= arr[i];
    subsequence(i+1,temp,n,arr,s,sum);

}

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> temp;
    cout<<"The subsequences are as follows"<<endl;
    int s = 0;
    subsequence(0,temp,n,arr,s,sum);
    return 0;
}