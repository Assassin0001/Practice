#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row;
    cin >> row;

    int **arr = new int *[row];
    int *colsize = new int [row];

    for (int i = 0; i < row; i++)
    {
        cout<<"Enter no of cols :-"<<" ";
        cin>>colsize[i];
        arr[i] = new int[colsize[i]];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout<<"Resultant 2D array :-"<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}