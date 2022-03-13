#include<bits/stdc++.h>
using namespace std;

int main()
{
   

   int n;
   cin>>n;

   for(int rows = 1;rows<=n;rows++)
   {    
       for(int colums = 1;colums<=n;colums++)
       {
           cout<<"*";
       }
       cout<<endl;
   }

   return 0;
}