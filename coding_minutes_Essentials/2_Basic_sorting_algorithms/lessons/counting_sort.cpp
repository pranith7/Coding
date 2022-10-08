#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void counting_sort(int a[], int n)
{   
    //Largest Element
    int largest = INT_MIN;
    for(int i=0;i<n;i++)
    {
        largest = max(largest,a[i]);
    }
    //Initialise frequency array
    vector<int> freq(largest+1, 0);

    //update frequency array
    for(int i=0;i<n;i++)
    {
        freq[a[i]]++;
    }

    //put back elements to main array
    int j=0;
    for(int i=0;i<=largest;i++)
    {
        while(freq[i]>0)
        {   
            a[j] = i;
            freq[i]--;
            j++;
        }
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    counting_sort(arr, n);
    for(int k=0;k<n;k++)
    {
        cout<<arr[k];
    }
    return 0;
}