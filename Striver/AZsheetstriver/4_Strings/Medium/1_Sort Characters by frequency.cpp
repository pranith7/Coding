#include<bits/stdc++.h>
using namespace std;

/*
    This code is a solution to a problem where the task is to sort a given string in non-decreasing order
    based on the frequency of its characters.

    The solution makes use of a hash map to store the frequency of each character in the input string 
    and a max heap to store the characters according to their frequency. The max heap is constructed by
    inserting pairs of the form (frequency, character) into the heap, with the frequency as the first 
    element of the pair. This ensures that the characters with the highest frequency are at the top of the heap.

    After the max heap is constructed, the solution processes the heap from top to bottom, adding each character 
    to the final string according to its frequency. The final string is constructed by repeating each character a
    number of times equal to its frequency.

    Finally, the sorted string is returned as the result.
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;           //for frequency of characters
        priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
        for(char c: s)
            freq[c]++;
        for(auto it: freq)
            maxheap.push({it.second,it.first}); //heap will be constructed on the basis of frequency
        s="";   
        while(!maxheap.empty()){
            s+=string(maxheap.top().first,maxheap.top().second); //frequency times the character
            maxheap.pop();
        }
        return s;
    }
};