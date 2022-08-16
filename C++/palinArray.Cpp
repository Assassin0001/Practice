#include<iostream>
#include<string.h>
using namespace std;
// } Driver Code Ends
/*Complete the function below*/
class Solution {
public:
    int PalinArray(int a[], int n)
    {
        bool flag=0;
        for(int i=0;i<n;i++){
            int num=a[i];
            int rev=0;
            int rem=0;
            while(num!=0){
                rem=num%10;
                rev=rev*10+rem;
                num/=10;
            }
            if(a[i]==rev)
               flag=1;
            else{
                flag=0;
                return 0;
            }   
        }
        return flag;
     
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends