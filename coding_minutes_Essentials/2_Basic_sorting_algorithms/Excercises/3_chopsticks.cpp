// #include<bits/stdc++.h>
// using namespace std;

// int pairSticks(vector<int> length, int D)
// {
//     // your code goes here
//     int pairs = 0;
//     sort(length.begin(),length.end());
//     for(int i=0;i<length.size()-1;i++)
//     {
//         if(length[i+1] - length[i] <= D)
//         {
//             pairs++;
//             i++;
//         }
//     }

//     return pairs;
// }
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr,int d)
{   
    int pairs = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<=arr.size()-1;i++)
    {
        for(int j=i+1;j<=arr.size()-1;j++)
        {
            if(arr[j] != arr[j-1] && arr[j] - arr[i] <= d)
             {  
                //  cout<<arr[i]<<" "<<arr[j];
                 pairs++;
             }
        }
       
    }
    return pairs;
}

void display(vector<int> arr)
{
        cout<<"output of the array is"<<endl;
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
}

int main()
{   

    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        vector<int> arr(n);
        for(int i=0;i<arr.size()-1;i++)
        {
            cin>>arr[i];
        }
        cout<<"ans "<<solve(arr,d)<<endl;
        // display(arr);
    }
    
    return 0;
}