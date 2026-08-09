class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int streak = 1;
        int best = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                // Ignore duplicates
                continue;
            }

            if (nums[i] == nums[i - 1] + 1) {
                streak++;
            } else {
                streak = 1;
            }

            best = max(best, streak);
        }

        return best;
    }
};