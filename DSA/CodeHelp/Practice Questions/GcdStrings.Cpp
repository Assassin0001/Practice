class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
    if(str2.length() > str1.length()) swap(str1,str2);
    return str1 == str2? str1:
     str1.substr(0,size(str2)) != str2? "": 
                                            gcdOfStrings(str1.substr(size(str2)),str2);
    }
};

//Optimized for Lines of Code

string gcdOfStrings(string s1, string s2) 
{
	return s1+s2==s2+s1 ? s1.substr(0, gcd(size(s1), size(s2))) : "";
}