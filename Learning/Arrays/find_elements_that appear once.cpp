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
        common_bit_mask = 
    }
}