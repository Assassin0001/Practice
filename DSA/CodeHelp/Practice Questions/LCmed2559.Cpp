//Brute Force
// T.C -> O(m^n)
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');

        for(int i=0;i<queries.size();i++){
            int value = 0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                if(vowels.count(words[j][0])>0 && vowels.count(words[j][words[j].length()-1])>0)
                   value++;
            }
            ans.push_back(value);
        }
        return ans;
    }
};
//Optimized Solution - Prefix Sum Method (As string is not mutable) 
// T.C. -> O(m+n)
class Solution {
private:
    bool check(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v,ans;
        v.push_back(0);
        for(auto w:words){
            v.push_back(v.back() + (check(w[0]) && check(w.back())));
        }
        for(auto q:queries){
            ans.push_back(v[q[1]+1] -v[q[0]]);
        }
        return ans;
    }
};
