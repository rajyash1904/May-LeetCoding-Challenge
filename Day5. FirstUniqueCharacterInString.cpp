/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

*/

class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> count(26,0);
        
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        
        for(int i=0;i<s.size();i++){
            if(count[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
