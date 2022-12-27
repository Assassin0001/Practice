class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
       int n = mat.size();
       bool ans[4] ={1,1,1,1};
       for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
               if(mat[i][j] != target[i][j]) ans[0] = false;
               if(mat[j][n-i-1] != target[i][j]) ans[1] = false;
               if(mat[n-i-1][n-j-1] != target[i][j]) ans[2] = false;
               if(mat[n-j-1][i] != target[i][j]) ans[3] = false;
           }
       } 
       return (ans[0] || ans[1] || ans[2] || ans[3]);
    }
};