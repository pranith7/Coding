#include <iostream>
#include <string>
#include <unordered_map>

std::string minWindow(const std::string& s, const std::string& t) {
  if (s.empty() || t.empty()) {
    return "";
  }

  std::unordered_map<char, int> dictT;
  for (int i = 0; i < t.length(); i++) {
    int count = dictT.count(t[i]) ? dictT[t[i]] : 0;
    dictT[t[i]] = count + 1;
  }

  int required = dictT.size();

  // Filter all the characters from s into a new list along with their index.
  // The filtering criteria is that the character should be present in t.
  int filteredS[s.length()];
  char chars[s.length()];
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    if (dictT.count(c)) {
      filteredS[count] = i;
      chars[count] = c;
      count++;
    }
  }

  int l = 0, r = 0, formed = 0;
  std::unordered_map<char, int> windowCounts;
  int ans[3] = {-1, 0, 0};

  // Look for the characters only in the filtered list instead of entire s.
  // This helps to reduce our search.
  // Hence, we follow the sliding window approach on as small list.
  while (r < count) {
    char c = chars[r];
    int count = windowCounts.count(c) ? windowCounts[c] : 0;
    windowCounts[c] = count + 1;

    if (dictT.count(c) && windowCounts[c] == dictT[c]) {
      formed++;
    }

    // Try and contract the window till the point where it ceases to be 'desirable'.
    while (l <= r && formed == required) {
      c = chars[l];

      // Save the smallest window until now.
      int end = filteredS[r];
      int start = filteredS[l];
      if (ans[0] == -1 || end - start + 1 < ans[0]) {
        ans[0] = end - start + 1;
        ans[1] = start;
        ans[2] = end;
      }

      windowCounts[c]--;
      if (dictT.count(c) && windowCounts[c] < dictT[c]) {
        formed--;
      }
      l++;
    }
    r++;
  }
  return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
}

int main() {
  std::cout << minWindow("ADOBECODEBANC", "ABC") << std::endl;
  return 0;
}
