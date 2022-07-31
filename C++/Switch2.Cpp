#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Ruppees: ";
    cin>>n;
    while(n!=0){
    int a;
    cout<<"Enter denomination you want to know: ";
    cin>>a;  
    int rem =0;    
    switch(a){
        case 100:
         rem=n/100;
         cout<<rem<<endl;
         n=n%100;
         break;
        case 50:
         rem=n/50;
         cout<<rem<<endl;
         n=n%50;         
         break;
        case 20:
         rem=n/20;
         cout<<rem<<endl;
         n=n%20;        
         break;   
        case 1:
         rem=n/1;
         cout<<rem<<endl;
         n=n%1;
         break;         
        default :
        cout<<"Please enter denomination.";
        break;       
     }
    
    }
    return 0;
}