vector<int> minAnd2ndMin(int arr[], int n) {
    vector<int> set;
    int s1=INT_MAX;
    int s2=INT_MAX;
    if(n<2){
        set.push_back(-1);
        set.push_back(-1);
        return set;
    }
    for(int i=0;i<n;i++){
        if(arr[i]<s1){
            s1=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]<s2 && arr[i]!=s1){
            s2=arr[i];   
        }
    }    
    if(s1!=s2 && s2!=INT_MAX){
        set.push_back(s1);
        set.push_back(s2);
    }
    else
        set.push_back(-1);
        
    return set;