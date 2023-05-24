#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int row=1;
    while(row<=n){

    //Print 1st Pattern
        int col=1;
        while(col<=n-row+1){
            cout<<col;
            col++;
        }
    //Print stars    
        int star = row-1;
        while(star){
            cout<<"**";
            star--;
        }
    //Print 2nd Pattern  
        int col2=1;
        int value=row;
        while(col2<=n-row+1){
            cout<<n-value+1;
            col2++;
            value++;
        } 
        cout<<endl;
        row++;
    }
    return 1;
}