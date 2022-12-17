class Solution {
private:
    bool valid(char ch){
        if((ch >= 'A' && ch <='Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <='9')){
            return 1;
        }
        return 0;
    }

    char toLowerCase(char ch){
        if(ch >='A' && ch <='Z'){
            char temp = ch-'A'+'a';
            return temp;
        } 
        else return ch;
    }

    bool checkPalindrome(string str){
        int s = 0;
        int e = str.length() - 1;

        while (s <= e)
        {
            if (str[s] != str[e]) return 0;
            else
            {
                s++;
                e--;
            }
        }
        return 1;
}

public:
    bool isPalindrome(string str) {
        string temp = "";

        //Remove unwanted characters
        for(int i =0; i<str.length(); i++){
            if(valid(str[i])) temp.push_back(str[i]);
        }

        //Conert into lowercase characters
        for(int i =0; i<temp.length(); i++){
            temp[i] = toLowerCase(temp[i]);
        }

        //Check palindrome
        return checkPalindrome(temp);
    }
};