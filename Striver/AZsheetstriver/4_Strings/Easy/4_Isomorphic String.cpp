#include <bits/stdc++.h>
using namespace std;

/*
    This is a C++ class that contains a method isIsomorphic() which determines if two strings, s and t, 
    are isomorphic. An isomorphic string is a string that can be transformed into another string by replacing
    certain characters with other characters, without changing the order of the characters.

    The method first declares two map variables, s_map and t_map, to store the character mappings from s to t 
    and from t to s, respectively. It then iterates through the characters in s using a while loop.

    For each character s[i] in s, the method checks if it has already been mapped to a character in t. 
    If it has, it checks if the mapped character is the same as the character at the same position in t. 
    If the mapped character is different, the method returns false as the strings are not isomorphic.

    If the character has not been mapped yet, the method checks if the character at the same position in t 
    has already been mapped to a character in s. If it has, it checks if the mapped character is the same as s[i]. 
    If the mapped character is different, the method returns false as the strings are not isomorphic.

    If both checks are false, the method adds a mapping from s[i] to t[i] in s_map and a mapping from t[i] 
    to s[i] in t_map.

    After the loop ends, the method returns true as the strings are isomorphic.

    There are three other versions of the method that use different data structures to store the character 
    mappings. The first version uses two unordered_map variables, the second version uses two map variables, 
    and the third version uses two arrays, cs and ct, to store the character mappings. All three versions use 
    a similar approach to determine if the strings are isomorphic.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    
    map<char, char> s_map, t_map;
        int i = 0;
        while(i < s.length())
        {
            if(s_map.count(s[i])) { if(s_map[s[i]]!=t[i]) return false; }
            else if(t_map.count(t[i])) { if(t_map[t[i]] != s[i]) return false; }
            else s_map[s[i]] = t[i], t_map[t[i]] = s[i];
            i++;
        }
        return true;

    unordered_map<char, char> s_map, t_map;
        int i = 0;
        while(i < s.length())
        {
            if(s_map.count(s[i])) { if(s_map[s[i]]!=t[i]) return false; }
            else if(t_map.count(t[i])) { if(t_map[t[i]] != s[i]) return false; }
            else s_map[s[i]] = t[i], t_map[t[i]] = s[i];
            i++;
        }
        return true;


    int cs[128] = {0}, ct[128] = {0};
    for(int i=0; i<s.size(); i++)
    {
        if(cs[s[i]] != ct[t[i]]) return false;
        else if(!cs[s[i]]) //only record once
        {
            cs[s[i]] = i+1;
            ct[t[i]] = i+1;
        }
    }
    return true;
    }
};