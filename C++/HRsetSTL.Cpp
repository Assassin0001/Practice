#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() { 
    set<int> s;
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        int q,num;
        cin>>q;
        switch(q){
            case 1:
             cin>>num;
             s.insert(num);
             break;
            case 2:
             cin>>num;
             s.erase(num);
             break;
            case 3:
             cin>>num;
             auto pos=s.find(num);
             if(pos!=s.end()){
                 cout<<"Yes"<<endl;
             }
             else{
                 cout<<"No"<<endl;
             }
             break;   
        }
    }
    return 0;
}



