// OJ: https://leetcode.com/problems/reverse-words-in-a-string-ii/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void reverseWords(vector<char>& s) {
        int i = 0, N = s.size();
        while (i < N) {
            int start = i;
            while (i < N && s[i] != ' ') ++i;
            reverse(begin(s) + start, begin(s) + i);
            ++i;
        }
        reverse(begin(s), end(s));
    }
};