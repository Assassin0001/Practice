// 1st Appoach - Naive Approach
class Solution {
public:
    bool isPalindrome(int x) {
        int a = x;
        unsigned int rev=0,rem=0;
        while(a!=0){
            rem=a%10;
            rev=rev*10+rem;
            a=a/10;
        }
        if(x<0){
            return false;
        }
        if(rev==x){
            return true;
        }
        return false;
    }
};

// 2nd Approach - To convert to a string.
class Solution {
public:
    bool isPalindrome(int x) {
        string rev = to_string(x);
        reverse(rev.begin(), rev.end());
        return to_string(x) == rev;
    }
};