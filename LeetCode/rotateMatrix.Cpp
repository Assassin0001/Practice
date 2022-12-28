class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     int n = matrix.size();
     for(int i=0; i<n; i++){
         reverse(matrix[i].begin(),matrix[i].end());
     }    
     for(int i=0; i<n; i++){
         //To swap all elements lying before the diagonal line.
         for(int j=0; j<n-i-1; j++){
             swap(matrix[i][j],matrix[n-j-1][n-i-1]); //To swap along alternateKad diagonal line.
         }
     }   
    }
};