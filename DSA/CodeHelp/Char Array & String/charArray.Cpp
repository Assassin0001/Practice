#include <bits/stdc++.h>
using namespace std;

char toLowerCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
    else
        return ch;
}

bool checkPalindrome(char str[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if (toLowerCase(str[s]) != toLowerCase(str[e]))
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
        return 1;
    }
}

int getlength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void rev(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(name[s++], name[e--]);
    }
}

char getmaXOccuringChar(string str){

    int arr[26] = {0};

    for(int i = 0; i< str.length(); i++){
        char ch = str[i];
        int number = 0;

        //lowercase
        if(ch >= 'a' && ch <= 'z')  number = ch-'a';
        //uppercase
        else number = ch-'A';
        arr[number]++;
    }

    int maxi = -1, ans = 0;
    for(int i=0; i<26; i++){
        if(maxi < arr[i]) {
            ans = i;
            maxi=arr[i];
        }
    } 

    return 'a'+ans;
}

int main()
{
    /*
    char name[20];
    cout << "Enter your name : ";
    cin >> name;

    int n = getlength(name);
    cout << "Length of String is: " << n << endl;

    rev(name, n);
    cout << "Reverse of String is: " << name << endl;

    if (checkPalindrome(name, n))
        cout << "String is Palindrome";
    else
        cout << "String is not Palindrome";
        */
       string s;
       cin>>s;
       cout<<getmaXOccuringChar(s);


    return 0;
}