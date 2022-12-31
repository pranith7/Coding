#include<bits/stdc++.h>
using namespace std;

/*
	This code is a solution to a problem where the task is to convert a Roman numeral to an integer.

	The solution first defines a map "mp" that maps each Roman numeral to its corresponding integer value.
	It then initializes a variable "res" with the integer value of the last character in the input string, 
	which is the least significant digit of the Roman numeral.

	The solution then iterates through the input string from left to right, skipping the last character. 
	For each character, it checks if the integer value of the current character is less than the integer 
	value of the next character. If this is the case, it means that the current character is a lesser value
	digit that is being subtracted from the next character to form a larger value. In this case, the solution 
	subtracts the value of the current character from "res". Otherwise, it means that the current character 
	is a larger value digit and it is added to "res".

	After iterating through the entire string, the final value of "res" is returned as the result.

	For example, if the input string is "MCMXCIV", the solution would start by initializing "res" to 4 
	(the integer value of the last character 'IV'). It would then iterate through the string, adding and 
	subtracting values as needed. This would result in a final value of "res" equal to 1994, which is the 
	integer equivalent of the input Roman numeral.
*/

class Solution {
public:
    int romanToInt(string s) {
	unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
	int res = mp[s.back()];
	for(int i = 0; i < s.size() - 1; i++) {
		if(mp[s[i]] < mp[s[i + 1]]) res -= mp[s[i]];
		else res += mp[s[i]];
	}
	return res;
}
};