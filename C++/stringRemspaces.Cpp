#include<iostream>
#include<string>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string modify (string s)
    {
        //code here.
        for(int i=0;i<s.size();i++){
            if(s[i] ==' '){
                s.erase(i,1);
                i--;
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
    return 0;
}
