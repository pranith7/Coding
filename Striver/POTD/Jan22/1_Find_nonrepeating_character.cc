#include <bits/stdc++.h> 
using namespace std;

char findNonRepeating(string str) {
    // Write your code here.
    int n = str.size();
    int count[256] = {0};
    for(int i=0;i<n;i++){
        count[str[i]]++;
    }
    for(int i=0;i<n;i++)
        if(count[str[i]] == 1) return str[i];
    
    return '#';
}


int main() {
    string str;
    cout<<"Enter the string:";
    cin>>str;
    cout<<"First non repeating character is: "<<findNonRepeating(str)<<endl;
    return 0;
}
