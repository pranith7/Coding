#include<bits/stdc++.h>
using namespace std;

vector<int> first_negative_number_of_every_size_k(vector<int>&arr, int k)
{   
    vector<int> result; 
    int n = arr.size();
    for (int i = 0; i <= n - k; i++) {
        int j = i;
        while (j < i + k) {
            if (arr[j] < 0) {
                result.push_back(arr[j]);
                break;
            }
            j++;
        }
        if (j == i + k) {
            result.push_back(0);
        }
    }
    return result;
}

template <typename Iterator, typename UnaryPredicate>
Iterator my_find_if(Iterator first, Iterator last, UnaryPredicate pred) {
    for (; first != last; ++first) {
        if (pred(*first)) {
            return first;
        }
    }
    return last;
}

vector<int> first_negative_number_of_every_size_k(vector<int>&arr, int k)
{   
    vector<int> result; 
    int n = arr.size();
    for (int i = 0; i <= n - k; i++) {
        auto it = std::find_if(arr.begin() + i, arr.begin() + i + k, [](int x) { return x < 0; });
        result.push_back(it != arr.begin() + i + k ? *it : 0);
    }
    return result;
}



int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maximumsubarraysum(arr)<<" "<<endl;
    return 0;
}

