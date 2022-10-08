#include<iostream>
using namespace std;


void solve(int arr[],int num)
{   
    int temp;
    for(int i=0; i<num; i++)
    {
        cout << "enter the element"<< i+1<< ":";
        cin>>arr[i];

    }
    for (int i=0;int j=num-1;i<num/2,i++,j--)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    cout << "\n Reverse all elements of array:"<< endl;

    for (int i=0; i<num; i++)
    {
        cout << arr[i]<<" ";
        
    }
}


int main()
{
    int arr[50],num,temp,i,j;
    cout<<"enter the total no.you want to enter";
    cin>>num;

    solve(arr,num);
    return 0;
}

