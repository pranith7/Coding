#include <algorithm>
#include <string>
#include <unordered_map>

/*
    This function takes two strings as input: the text string, which is the string in which 
    to search for the anagram, and the anagram string, which is the string that you are 
    searching for. It uses an std::unordered_map to store the count of each character in 
    the anagram, and then iterates through the text string, updating the count of matched 
    characters in the anagram. When the number of matched characters is equal to the length
    of the anagram, it increments a counter and resets the matched characters count.

It will work for all types of characters. But for case-sensitive search, you need to make a
 few modifications in the code accordingly.

It is also worth to mention that this function has a time complexity of O(n), where n is
 the length of the text.
*/

int countAnagramOccurrences(const std::string& text, const std::string& anagram) {
    std::unordered_map<char, int> charCounts;
    for (char c : anagram) {
        charCounts[c]++;
    }
    int count = 0;
    int matched = 0;
    for (int i = 0; i < text.length(); i++) {
        char right = text[i];
        if (charCounts.find(right) != charCounts.end()) {
            charCounts[right]--;
            if (charCounts[right] >= 0) {
                matched++;
            }
            if (matched == anagram.length()) {
                count++;
                char left = text[i-matched+1];
                charCounts[left]++;
                if (charCounts[left] > 0) {
                    matched--;
                }
            }
        } else {
            matched = 0;
            charCounts.clear();
            for (char c : anagram) {
                charCounts[c]++;
            }
        }
    }
    return count;
}

/*
    In this example, I have replaced std::unordered_map with an array charCounts of 
    fixed size, with each index representing a character and the value at that index
     representing the count of that character in the anagram.

    I also modified the indices of the array, so instead of using a map to find the 
    index, i used c-'a' to find the index, which also assumes the text and anagram 
    only contains lowercase alphabet.
*/

#include <algorithm>
#include <string>

const int MAX_CHARS = 26;

int countAnagramOccurrences(const std::string& text, const std::string& anagram) {
    int charCounts[MAX_CHARS] = {0};
    for (char c : anagram) {
        charCounts[c - 'a']++;
    }
    int count = 0;
    int matched = 0;
    for (int i = 0; i < text.length(); i++) {
        char right = text[i];
        if (charCounts[right - 'a'] > 0) {
            charCounts[right - 'a']--;
            matched++;
            if (matched == anagram.length()) {
                count++;
                matched--;
                char left = text[i-matched+1];
                charCounts[left - 'a']++;
            }
        } else {
            matched = 0;
            for (int j = 0; j < MAX_CHARS; j++) {
                charCounts[j] = 0;
            }
            for (char c : anagram) {
                charCounts[c - 'a']++;
            }
        }
    }
    return count;
}
