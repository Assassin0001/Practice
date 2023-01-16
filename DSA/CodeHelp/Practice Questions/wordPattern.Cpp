class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string temp="";
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                v.push_back(temp);
                temp="";
            }
            else{
                temp=temp+s[i];
            }
        }
        v.push_back(temp);
        // store word in words

        if(v.size()!=pattern.size()){
            return false;
        }
        // if size does not match return false
        
        unordered_map<char, string> m;
        unordered_set<string> st;
        //Got it..
        for(int i=0; i<pattern.size(); i++){
            if(m.find(pattern[i])!=m.end()){//pattern in hashmap .... if yes check its value is equal to pattern value.
                if(m[pattern[i]]!=v[i]){
                    return false;
                }
            }
            else{// pattern not in hashmap ... check if its value is distinct or not !!
                if(st.count(v[i])>0){
                    return false;
                }
                m[pattern[i]]=v[i];
                st.insert(v[i]);
            }
        }
        return true;
    }
};