/*
We have an horizontal number line. On that number line, we have gas stations at positions 
stations[0], stations[1], ..., stations[N-1], where N = size of the stations array. Now, we 
add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized. 
We have to find the smallest possible value of D. Find the answer exactly to 2 decimal places.

Example 1:

Input:
N = 10
stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
K = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
Example 2:

Input:
N = 10
stations = [3,6,12,19,33,44,67,72,89,95]
K = 2
Output: 14.00
Explanation: Construction of gas stations at 86 locations
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


/*
    This is a C++ class that contains a method findSmallestMaxDist() which uses a binary search 
    algorithm to find the smallest maximum distance between petrol stations that can be placed 
    along a road with a given set of petrol stations. The petrol stations are represented by a 
    vector of integers stations, and the number of petrol stations to be placed is specified by 
    the parameter k.

    The method begins by defining the variables left and right to represent the left and right bounds
    of the search range, respectively. It initializes left to 0 and right to the difference between 
    the last and first elements of stations.

    The method then enters a loop that continues until the difference between right and left is 
    greater than 1e-6. In each iteration of the loop, it calculates the midpoint between left and
    right and stores it in the variable mid. It then calls the function isPossible() with the value
    of mid, the vector stations, and the value of k.

    The function isPossible() iterates through the elements of the vector stations and calculates 
    the number of petrol stations that need to be added between each pair of adjacent petrol stations
    in order to maintain a distance of at least dist between them. If the total number of petrol stations
    needed is less than or equal to k, the function returns true. If the total number is greater than k, 
    the function returns false.

    If isPossible() returns true, the method updates right to be mid and continues the loop. If isPossible()
    returns false, the method updates left to be mid and continues the loop.

    Finally, when the loop ends, the method returns left+0.000001, which is the smallest maximum distance
     between petrol stations that can be placed along the road with the given set of petrol stations.
*/
// } Driver Code Ends
class Solution {
  public:
      bool isPossible(double dist,vector<int> &stations, int k){
    
            int stationsToAdd=0;
    
            for(int i=0;i<stations.size()-1;i++){
    
                stationsToAdd+=floor((stations[i+1]-stations[i])/dist);
    
            }
    
            return stationsToAdd<=k;
    
        }
    
        double findSmallestMaxDist(vector<int> &stations, int k) {
    
            // Write your code here
    
            double left=0,right=stations[stations.size()-1]-stations[0];
    
            while((right-left)>1e-6){
    
                double mid=left + (right-left)/2.0;
    
                if(isPossible(mid,stations,k))right=mid;
    
                else left=mid;
    
            }
    
            return left+0.000001;
    
        }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends