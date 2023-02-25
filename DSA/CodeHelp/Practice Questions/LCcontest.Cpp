#include <bits/stdc++.h>
using namespace std;

int minMaxDifference(int num) {
    int maxnum = 0;
    int minnum = 0;
    vector<int> max;
    
    while(num){
        int digit = num%10;
        num/=10;
        max.push_back(digit);
    }
    int l = max.size();
    
    vector<int> min;
    for(int i=0;i<l;i++){
        min.push_back(max[i]);
    }
    
    int maxdigit,mindigit = min[l-1];
    //For finding maxdigit
    for(int i=l-1; i>=0; i--){
        if(max[i] != 9){ 
            maxdigit = max[i];  
            break;
        }
    }
    
    for(int i=0;i<l;i++){
        if(max[i] == maxdigit) max[i] = 9;
        if(min[i] == mindigit) min[i] = 0;
        maxnum += max[i]*pow(10,i);
        minnum += min[i]*pow(10,i);
    }       
    return maxnum-minnum;
}

int main(){
    int n;cin>>n;
    int ans = minMaxDifference(n);
    cout<<ans<<endl;
    return 0;
}
