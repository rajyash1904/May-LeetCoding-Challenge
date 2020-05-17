/*

Find All Anagrams in a String


Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         map <char, int> m;
      int n = s.size();
      int left = 0, right = 0;
      int counter = p.size();
      vector <int> ans;
      for(int i = 0; i < p.size(); i++) m[p[i]]++;
      for(int right = 0; right < n; right++){
         if(m.find(s[right]) != m.end() && m[s[right]]){
            m[s[right]]--;
            counter--;
            if(counter == 0)ans.push_back(left);
         } else {
            while(left<right){
               if(m.find(s[left]) != m.end()) {
                  counter++;
                  m[s[left]]++;
               }
               left++;
               if(m.find(s[right]) != m.end() && m[s[right]]){
                  right--;
                  break;
               }
            }
            if(m.find(s[left])==m.end())left = right + 1;
         }
      }
      return ans;
        
    }
};
