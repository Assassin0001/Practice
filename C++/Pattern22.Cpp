#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int row=1;
    while(row<=n){

        int space=n-row;
    //Print spaces
        while(space){
            cout<<" ";
            space--;
        }
    //Print 1st nos    
        int col=1;
        while(col<=row){
           cout<<col;
           col++;
        }
    //Print 2nd nos
    /*  int col2=2;
        while(col2<=row){
            cout<<row-col2+1;
            col2++;
        } */
        int start = row-1;
        while(start){
            cout<<start;
            start--;
        }
        cout<<endl;
        row++;
    }
    return 1;
}