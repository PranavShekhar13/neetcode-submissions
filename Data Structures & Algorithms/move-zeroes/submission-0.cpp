class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> aux(n,0);
        int write = 0;

        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                aux[write++] = nums[i];
            }
        }
        nums = aux;
        
    }
};