class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false; 
        bool firstColZero = false;

        int m = matrix.size(); //Rows
         if(m==0) return;
        int n = matrix[0].size(); //Cols
        if(n==0) return;

        for(int i=0; i<n; i++){  // 1st Row zero - n(cols) because we check 1st row sideways
            if(matrix[0][i] == 0){ // Col by col
                firstRowZero = true;  //Mark first row if any zero and break
                break;
            }
        }

        for(int j=0; j<m; j++){ //1st Col zero - m(rows) because we check 1st col top-down
            if(matrix[j][0] == 0){// Row by Row
                firstColZero = true; //Mark first col if any zero and break
                break;
            }
        }

        for(int i=1; i<m; i++){       //Start from 2nd row
            for(int j=1; j<n; j++){  //2nd col
                if(matrix[i][j]==0){   //Check if value is 0
                    matrix[i][0] = 0; //Mark 1st Col
                    matrix[0][j] = 0; // & 1st Row
                }
            }
        }

            for(int i=1; i<m; i++){   //Start from 2nd row 
            for(int j=1; j<n; j++){  //2nd Col
                if(matrix[i][0]==0 || matrix[0][j] == 0){  //If 1st row or 1st col is marked
                    matrix[i][j] = 0;  //Make all row col elements 0  
                }
            }
        }

        if(firstRowZero){   //Make all first row elements 0
             for(int i=0; i<n; i++){
                matrix[0][i] = 0;
             }
        }

        if(firstColZero){  //Make all first col elements 0
             for(int j=0; j<m; j++){
                matrix[j][0] = 0;
             }
        }
       
    }
};
