#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int row=1;
    while(row<=n){
    //Print stars    
    /*  int col=n;
        while(col>=row){
           cout<<"*";
           col--;
        }*/
        int star=n-row+1;
        while (star)
        {
          cout<<"*";
          star--;
        }        
        cout<<endl;
        row++;
    }
    return 1;
}