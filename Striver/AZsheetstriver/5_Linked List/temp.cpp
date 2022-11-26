#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
       int a[n];
	   int b[n];
	   int j = 0;
	   int k = 0;
	   for(int i=0;i<n;i++)
	   {
	       if(arr[i] >= 0)
	        a[j++] = arr[i];
	       else
	        b[k++] = arr[i];
	   }
       int size1 = sizeof(a)/sizeof(a[0]);
       int size2 = sizeof(b)/sizeof(b[0]);
	   int i = 0;
	   k = 0;
	   j = 0;
	   while(i<n)
	   {    

           if(j<size1 and i%2 == 0) arr[i++] = a[j++];
           else if(k<size2 and i%2 == 1) arr[i++] = b[k++];
           else if(j<size1) arr[i++] = a[j++];
	       else if(k<size2) arr[i++] = b[k++];
            //  arr[i++] = b[k++];

           
	   }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    solve(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}