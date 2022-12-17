class Solution {
public:
    string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2*k) {
    	// end is either the kth position of the current segment or the last position in s
    	int start = i, end = min((int) s.size() - 1, start + k - 1);
    	while (start < end)
    		swap(s[start++], s[end--]);
    }
    return s;                
    }
};