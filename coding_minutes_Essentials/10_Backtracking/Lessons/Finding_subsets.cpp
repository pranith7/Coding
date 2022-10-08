#include<bits/stdc++.h>
using namespace std;

void solve(char *input,char *output,int i,int j)
{

    if(input[i]=='\0')
    {
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    //Inlcude the ith letter
    output[j] = input[i];
    solve(input,output,i+1,j+1);
    //Exclude the ith letter
    solve(input,output,i+1,j);
}


int main()
{
    char input[100];
    char output[100];
    cin>>input;
    solve(input,output,0,0);
    return 0;
}