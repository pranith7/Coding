#include<bits/stdc++.h>
using namespace std;

/*
	Time complexity: O(N)
	Space complexity: O(1)

	Where N is the size of array. 
*/
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int pivot(vector<int> &arr)
{
    int i = 0;
    int j = 0;
    while (i < arr.size())
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }
    return j;
}

void solve(vector<int> &arr)
{
    // Finding the point where negatives and positives seperate.
    int division = pivot(arr);

    // Positive element's index.
    int pos = division;
    // Negative element's index.
    int neg = 1;

    // 1. Positive index is in range.
    // 2. Negative index is less than positive index.
    // 3. Negative index contains negative  element only.
    while (pos < arr.size() && neg < pos && arr[neg] < 0)
    {
        swap(arr[pos], arr[neg]);
        neg += 2;
        pos++;
    }
    return;
}

void rearrange(vector<int> &arr)
{
	// Write your code here.
    vector<int> positive,negative;
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i] >= 0)
        {
           positive.push_back(arr[i]); 
        }
        else
        {
            negative.push_back(arr[i]);
        }
    }
    arr.clear();
    int m = positive.size();
    int k = negative.size();
    int i = 0, j = 0;
    while (i < k && j < m)
    {
        arr.push_back(negative[i]);
        i++;
        arr.push_back(positive[j]);
        j++;
    }
    while (i < k)
    {
        arr.push_back(negative[i]);
        i++;
    }
    while (j < m)
    {
        arr.push_back(positive[j]);
        j++;
    }

    return;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rearrange(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}