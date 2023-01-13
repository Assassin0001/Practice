#include <bits/stdc++.h>
using namespace std;

void solve(int *, int);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
    cout << "Rearranged Elements :-" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

void solve(int arr[], int n)
{
    int k = 0;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0) a[k++] = arr[i];
    }

    for(int i = 0; i<n; i++){
        if(arr[i] >= 0) a[k++] = arr[i];
    }

    for(int i = 0; i<n; i++){
        arr[i] = a[i];
    }

}
