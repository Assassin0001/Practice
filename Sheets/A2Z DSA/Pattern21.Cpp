#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int row=1;

    while(row<=n){

        int space=row-1;
    //Print spaces
        while(space){
            cout<<" ";
            space--;
        }
    //Print nos    
        int col=1;
        while(col<=n-row+1){
           cout<<col+row-1;
           col++;
        }
        cout<<endl;
        row++;
    }
    return 1;
}