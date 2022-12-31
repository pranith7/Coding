#include<bits/stdc++.h>
using namespace std;

    /*
        In this version of the quick_sort function, the pivot element is selected as the first element in the sublist. 
        The function then iterates through the sublist starting at the second element and partitions it into two sublists:
        one containing elements that are less than or equal to the pivot, and the other containing elements that are greater than the pivot.

        After the sublist is partitioned, the quick_sort function calls itself recursively to sort the two sublists on either side of the pivot. 
        When the sublists are small enough, the function returns control to the calling function and the sublists are combined back together to 
        form the final sorted list.

        There are pros and cons to selecting the pivot element from the start or the end of the list. One advantage of selecting the 
        pivot element from the start of the list is that it can help to avoid worst-case scenarios where the pivot is the largest or 
        smallest element in the list. However, selecting the pivot element from the start of the list can also lead to suboptimal 
        performance in some cases.
    */
void QuickSort(vector<int> &list,int start,int end)
{   

    // pivot = start
    if (start < end) {
    int pivot = list[start];
    int i = start + 1;

    for (int j = start + 1; j <= end; j++) {
      if (list[j] <= pivot) {
        std::swap(list[i], list[j]);
        i++;
      }
    }

    std::swap(list[start], list[i - 1]);
    int pivot_index = i - 1;

    QuickSort(list, start, pivot_index - 1);
    QuickSort(list, pivot_index + 1, end);
  }    
    /*
        In this version of the quick_sort function, the pivot element is chosen randomly using the random_device and mt19937 classes 
        from the random library. The random_device class generates random numbers, and the mt19937 class is a random number generator engine that uses a Mersenne Twister algorithm.

        The uniform_int_distribution class is used to generate a random integer in the range [start, end], inclusive. 
        The pivot element is chosen by generating a random integer using the dis(gen) expression and selecting the element at the 
        corresponding index in the list.

        After the pivot element is chosen, the function partitions the list into two sublists and calls itself recursively to sort the sublists. 
        When the sublists are small enough, the function returns control to the calling function and the sublists are combined back together to form the final sorted list.

        Using a randomly chosen pivot element can help to improve the performance of the quick sort algorithm by avoiding worst-case scenarios 
        where the pivot is the largest or smallest element in the list. However, it can also increase the running time slightly due to the overhead of generating random numbers.
    */
    // pivot = random
    if (start < end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start, end);

    int pivot_index = dis(gen);
    std::swap(list[end], list[pivot_index]);
    int pivot = list[end];

    int i = start;

    for (int j = start; j <= end - 1; j++) {
      if (list[j] <= pivot) {
        std::swap(list[i], list[j]);
        i++;
      }
    }

    std::swap(list[i], list[end]);
    pivot_index = i;

    QuickSort(list, start, pivot_index - 1);
    QuickSort(list, pivot_index + 1, end);
    }

    /*
        The quick_sort function uses a recursive approach to divide the list into smaller sublists and sort them. 
        It starts by selecting the last element in the sublist as the pivot element. 
        It then iterates through the sublist and partitions it into two sublists: 
            one containing elements that are less than or equal to the pivot, 
            and the other containing elements that are greater than the pivot.

        After the sublist is partitioned, the quick_sort function calls itself recursively to sort the two sublists 
        on either side of the pivot. When the sublists are small enough, the function returns control to the calling
         function and the sublists are combined back together to form the final sorted list.
    */
    //pivot = end
    if (start < end) {
            int pivot = list[end];
            int i = start - 1;

            for (int j = start; j <= end - 1; j++) {
                if (list[j] <= pivot) {
                    i++;
                    std::swap(list[i], list[j]);
                }
            }

            std::swap(list[i + 1], list[end]);
            int pivot_index = i + 1;

            QuickSort(list, start, pivot_index - 1);
            QuickSort(list, pivot_index + 1, end);
        }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    cout<<"After Sorting of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}