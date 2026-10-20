class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int streak = 1, best = 1;

        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1]+1) streak+=1;
            else streak = 1;
            best = max(best,streak);
        }
    return best;
    }
};
