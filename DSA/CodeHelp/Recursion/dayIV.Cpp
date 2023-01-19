#include<bits/stdc++.h>
using namespace std;

void rev(string& str,int s,int e){
    if(s>e) return;

    swap(str[s++],str[e--]);
    rev(str,s,e);
}

bool checkPalin(string& str,int i){
    int n = str.length();

    //Base Case
    if(i > n/2) return true;

    if(str[i] == str[n-i-1]){
        i++;
        checkPalin(str,i);
    }
    else return false;
}

int expo(int a,int b){
    if(b == 0) return 1;
    if(b == 1) return a;

    int ans = expo(a,b/2);
    if(b%2 == 0) return ans*ans;
    else return a*ans*ans; 
}

void sortArray(int* arr,int n){
    if(n==0 || n==1) return;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    }
    sortArray(arr,n-1); 
}

int main(){
    //Reverse String
    cout<<"Enter string: ";
    string str;cin>>str;
    int n = str.length();
    rev(str,0,n-1);
    cout<<"Reversed string: "<<str<<endl;

    //Check Palindrome
    if(checkPalin(str,0)) cout<<"A Palindorme"<<endl;
    else cout<<"Not a Palindrome"<<endl;

    //Exponentiation
    cout<<"Enter Number & Its Power: ";
    int a,b;cin>>a>>b;
    int ans = expo(a,b);
    cout<<"Answer is "<<ans<<endl;
    
    //Bubble Sort
    cout<<"Enter size of array: ";
    int n;cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sortArray(arr,n);
    cout<<"After Sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}