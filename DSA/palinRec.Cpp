#include<iostream>
using namespace std;

bool palinRec(string,int,int);

int main(){
    string s ="MADAM";
    int n= s.size();
    if(palinRec(s,0,n)){
        cout<<"Palindrome Number.";
    }
    else{
        cout<<"Not Palindrome Number.";
    }
}

bool palinRec(string s,int i,int n){
    if(i >= n/2){
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return palinRec(s,i+1,n);
}

    