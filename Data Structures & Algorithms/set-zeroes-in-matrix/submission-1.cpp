class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); //Rows
         if(m==0) return;
        int n = matrix[0].size(); //Cols
        if(n==0) return;

        vector<bool> rows(m,0);
        vector<bool> cols(n,0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;  //Mark Row Vector 1
                    cols[j] = 1; //Mark Col Vector 1
                }
            }
        }

        for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
                if( rows[i] == 1 || cols[j] == 1){  //If any of them is marked
                    matrix[i][j] = 0;  //Make that element 0 in matrix  
                }
            }
        }


       
    }
};
