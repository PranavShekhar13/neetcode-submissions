class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int n = r * c;
        int totalSum = (n*(n+1))/2;
        int sum =0;
        int missing = -1;
        int repeated = -1;
        unordered_set<int> hash;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                sum+=grid[i][j];
                if(hash.find(grid[i][j]) != hash.end()){
                    repeated = grid[i][j];
                }
                else{
                    hash.insert(grid[i][j]);
                }
            }
        }

        missing = totalSum  - sum + repeated;
       

        return {repeated, missing};
    }
};