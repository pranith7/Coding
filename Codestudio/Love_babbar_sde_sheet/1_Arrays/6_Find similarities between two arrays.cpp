#include<bits/stdc++.h>
using namespace std;


pair < int, int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) {
  int intersectionSize = 0;
  unordered_map < int, int > ma;

  for (int i = 0; i < n; i++)
    ma[arr1[i]] = 1;
  for (int i = 0; i < m; i++) {
    if (ma.count(arr2[i]) == 1)
      intersectionSize++;
  }

  int unionSize = n + m - intersectionSize; // Formula
  pair < int, int > res;
  res.first = intersectionSize;
  res.second = unionSize;

  return res;
}


int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> arr(n),arr1(m);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    for(int i = 0; i < m; i++)
        cin>>arr1[i];

    pair < int, int > res = findSimilarity(arr, arr1, n, m);
    cout<<"Output of program"<<endl;
    cout << res.first << " " << res.second << endl;
    return 0;
}