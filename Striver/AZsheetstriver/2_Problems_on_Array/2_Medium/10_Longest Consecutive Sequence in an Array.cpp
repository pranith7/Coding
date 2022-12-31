//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      /*
          The findLongestConseqSubseq function takes an array of integers called arr and an integer N as input, 
          and returns an integer representing the length of the longest consecutive subsequence in the array arr.

          The function first declares an unordered set s and inserts all the elements of the array arr into it. 
          It then declares the variables longestStreak and currentStreak, which will be used to keep track of 
          the longest and current streaks, respectively.

          The function then enters a loop that iterates over the elements of the array arr. For each element 
          arr[i], it checks if the element arr[i] - 1 is not present in the set s. If this is the case, 
          it means that the element arr[i] is the first element in a possible consecutive subsequence.

          The function then initializes the variable currentElement with the value of arr[i] and enters 
          another loop that iterates until the element currentElement is not present in the set s. For each 
          iteration, it increments the value of currentStreak by 1 and the value of currentElement by 1.

          After the inner loop ends, the function updates the value of longestStreak with the maximum of 
          currentStreak and longestStreak, and continues iterating over the elements of the array arr.

Finally, the function returns the value of longestStreak.
      */
      unordered_set<int>s;
      for(int i=0;i<N;i++) s.insert(arr[i]);
      int longestStreak = 0;
      for(int i=0;i<N;i++){
          
          if(s.find(arr[i] - 1) == s.end()){
              
              
              int currentElement = arr[i];
              int currentStreak = 0;
              
              while(s.find(currentElement) != s.end()){
                  
                  currentStreak++;
                  currentElement++;
              }
              
              longestStreak = max(currentStreak,longestStreak);
              
              
          }
      }
      
      return longestStreak;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends