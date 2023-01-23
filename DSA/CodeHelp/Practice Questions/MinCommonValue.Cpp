#include <bits/stdc++.h>
using namespace std;

int minCommonValue(vector<int> nums1,vector<int> nums2){
        int m = nums1.size();
        int n = nums2.size();
        int i=0;
        int j =0;
        while(i<m && j<n){
            if(nums1[i] == nums2[j]) return nums1[i];
            else if(nums1[i] > nums2[j]) j++;
            else if(nums1[i] < nums2[j]) i++;
        }
    return -1;
}

int main() {
    vector<int> arr(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
     
    vector<int> arr2(2);
    arr2.push_back(1);
    arr2.push_back(4);
	cout<<minCommonValue(arr,arr2);
    return 0;
}