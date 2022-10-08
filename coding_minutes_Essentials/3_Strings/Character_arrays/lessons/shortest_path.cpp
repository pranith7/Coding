#include<bits/stdc++.h>
using namespace std;

int main()
{
    char route[1000];
    cin.getline(route,1000);

    int x = 0,y = 0;
    for(int i=0;route[i]!='\0';i++)
    {
        switch(route[i])
        {
            case 'N': y++;
                      break;
                    
            case 'S': y--;
                      break;

            case 'E': x++;
                      break;
            
            case 'W': x--;
                      break;
        }
    }
    cout<<"X "<<x<<","<<"Y "<<y<<endl;

    if(x>=0 and y>=0) 
    {
        while(x--) cout<<"E";
        while(y--) cout<<"N";
    }
    else if(x>=0 and y<0)
    {
        while(x--) cout<<"E";
        y = abs(y);
        while(y--) cout<<"S";
    }
    else if(y>=0 and x<0)
    {   
        x = abs(x);
        while(x--) cout<<"W";
        while(y--) cout<<"N";
    }
    else
    {   
        y = abs(y);
        while(y--) cout<<"S";
        x = abs(x);
        while(x--) cout<<"W";

    }
    return 0;
}