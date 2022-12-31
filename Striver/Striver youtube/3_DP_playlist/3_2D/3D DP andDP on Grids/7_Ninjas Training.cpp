#include<bits/stdc++.h>
using namespace std;

/*
    This is a function that uses recursion and memorization to find the maximum number of points that
    can be obtained by a ninja in training.

    The function takes in two arguments:

    n: This is an integer representing the number of days of training.
    points: This is a 2D vector of integers representing the number of points that can be obtained
    for each activity on each day of training. The activities are represented by the indices of the 
    inner vector (0 for meditation, 1 for running and 2 for fight).
    The function has a helper function f which takes in four arguments:

    day:    This is an integer representing the current day of training.
    last:   This is an integer representing the activity that was done on the previous day.
    points: This is a 2D vector of integers representing the number of points that can be
            obtained for each activity on each day of training.
    dp:     This is a 2D vector of integers representing the memorized values.

    The function f has a base case where if the current day is zero (the first day of training), 
    it returns the maximum number of points that can be obtained from the activities on the first 
    day, excluding the activity that was done on the previous day (since the ninja cannot do the 
    same activity two days in a row).

    For all other days, the function f iterates through all the activities and finds the maximum
    number of points that can be obtained by adding the number of points for the current activity
    on the current day to the maximum number of points obtained from the previous day by doing a 
    different activity. It then stores this maximum value in the dp array and returns it.

    The main ninjaTraining function then calls the helper function f with the appropriate 
    arguments and returns the result.
*/
int f(int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {

  if (dp[day][last] != -1) return dp[day][last]; //checking dp subarray

  if (day == 0) { //Base case
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }

  }

  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector < vector < int > > & points) {  // Recursion + memorisation

  vector<vector<int>> dp(n, vector<int> (4, -1));
  return f(n - 1, 3, points, dp);
}

int ninjatraining(int n,vector<vector<int>> &points) // tabulation
{
    vector<vector<int>> dp(n, vector<int> (4,0));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][1],max(points[0][0],points[0][2]));

    for(int day=1;day<n;day++)
    {
        for(int last = 0;last<4;last++)
        {
            dp[day][last] = 0;
            for(int task = 0;task<3;task++)
            {
                if(task!=last)
                {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }

            }
        }
    }
    return dp[n-1][3];
}

int ninjaTraining(int n, vector < vector < int > > & points) { // Space optimisation

  vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {

    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int>> points(n,vector<int> (3));
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>points[i][j];

    cout<<ninjatraining(n,points);

    return 0;
}