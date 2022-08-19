#include<bits/stdc++.h>
using namespace std;

/*    Time Complexity: O(N*M)    
      Space Complexity: O(M)    
      Where N is the given integer and M is the size of the result array. 
*/

void helper(vector<int> &result, int x) {    
    // Inititalise carryOver as 0.    
    int carryOver = 0;
   for (int i = 0; i < result.size(); i++)    
   {        
       int value = result[i] * x + carryOver;    
       result[i] = value % 10; // Store last digit of value in the result.    
      carryOver = value / 10; // Remove the last digit from value and carry the remaining value.        
       }
      while (carryOver != 0) // Run the loop until carryOver doesn't become zero.       
      {        
       result.push_back(carryOver % 10);  // Push the last digit of carryOver in result array.                 
      carryOver = carryOver / 10;   // Update the carryOver.    
      } 
}

string calculateFactorial(int n)
{    
      vector<int> result;
      result.push_back(1); //    Enter 1 as the first element in the factorial array/list.
    for (int x = 2; x <= n; x++) // Run loop for calculating factorial for rest of the elements.    
    {        
        helper(result, x);     // Call the helper function for each x and update the result array/list. 
    }     
    string ans = ""; // We are representing answer in a string format.
   for (int i = result.size() - 1; i >= 0; i--)    
   {  
       ans.push_back((char)(result[i] + '0'));    
   }
   return ans; 
}

int main()
{   
    int n;
    cin>>n;
    cout<<calculateFactorial(n);
    return 0;
}