#include <bits/stdc++.h>
using namespace std;

int minMaxDifference(int num) {
    int maxnum = 0;
    int minnum = 0;
    vector<int> temp;
    
    while(num){
        int digit = num%10;
        num/=10;
        temp.push_back(digit);
    }
    int l=temp.size();
    
    vector<int> temp2;
    for(int i=0;i<l;i++){
        temp2.push_back(temp[i]);
    }
    
    //For finding maxdigit
    int tempmaxdigit = 0;
    int tempmindigit = temp2[l-1];
    for(int i=l-1; i>=0; i++){
        if(temp[i] != 9) tempmaxdigit = temp[i];  
        break;
    }
    
    for(int i=0;i<l;i++){
        if(temp[i] == tempmaxdigit) temp[i] = 9;
    }
    
    for(int i=0;i<l;i++){
        if(temp2[i] == tempmindigit) temp2[i] = 0;
    }
    
    for(int i=0;i<l;i++){
        maxnum += temp[i]*pow(10,i);
        minnum += temp2[i]*pow(10,i);
    }
                
    return maxnum-minnum;
}

int main(){
    int n;cin>>n;
    int ans = minMaxDifference(n);
    cout<<ans<<endl;
}
