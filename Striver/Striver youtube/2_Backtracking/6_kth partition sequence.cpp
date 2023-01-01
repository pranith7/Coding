#include<bits/stdc++.h>
using namespace std;

/*
    This function is used to find the Kth permutation of a list of numbers from 1 to N.

    The function first calculates the factorial of N-1, which is stored in the variable "fact". 
    It then creates a vector called "numbers" that stores all the numbers from 1 to N.

    The function then decrements the value of K by 1. This is because the problem states that the 
    permutation should start from the 0th index, while the vector "numbers" is 0-indexed.

    The function then enters a while loop which will run until all the numbers in the "numbers" 
    vector have been used up. In each iteration of the loop, the function appends the K/fact-th 
    element of the "numbers" vector to the string "ans". It then removes the element from the "numbers" vector.

    The function then calculates the new value of K by taking the modulo of K and "fact", and updates
    the value of "fact" to be the factorial of the size of the "numbers" vector.

    Finally, when the "numbers" vector is empty, the function breaks out of the while loop and 
    returns the permutation stored in the "ans" string.
*/
string solve(int n,int k)
{
    int fact = 1;
    vector<int> numbers;
    for(int i=1;i<n;i++)
    {
        fact = fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k-1;
    while(true)
    {
        ans = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0) break;
        k %= fact;
        fact /= numbers.size(); 
    }

    return ans;

}

int main()
{
    int n,k;
    cin>>n>>k;
    string ans;
    ans = solve(n,k);
    cout<<ans<<endl;
    return 0;
}