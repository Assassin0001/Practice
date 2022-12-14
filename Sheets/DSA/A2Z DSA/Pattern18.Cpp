#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int row =1;
    while(row<=n){

        int space=n-row;
    //Print spaces
        while(space){
            cout<<" ";
            space--;
        }
    //Print stars    
        int col=1;
        while(col<=row){
           cout<<"*";
           col++;
        }
        cout<<endl;
        row++;
    }
    return 1;
}