#include <bits/stdc++.h>
using namespace std;

int getsingle (int arr[], int n)
{
    int ones =  0, twos = 0;
    int common_bit_mask;

    for (int i = 0; i < n; i++)
    {
        twos = twos | (ones & arr[i]);
        ones = ones ^ arr[i];
        common_bit_mask = ~ (ones & twos);
        ones &= common_bit_mask;
        twos &= common_bit_mask;

    
    }

    return ones;

}

int main ()
{
  int arr[] = { 5 ,4 ,3,2,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "the element with single occurance is "
       << getsingle(arr, n);
}