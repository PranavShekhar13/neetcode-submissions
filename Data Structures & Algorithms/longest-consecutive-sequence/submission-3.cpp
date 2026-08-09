class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int best = 0;

        unordered_set<int> numset(nums.begin(), nums.end());

        for(int num:numset){
            if(numset.find(num-1) == numset.end()){
                int currentNum = num;
                int streak = 1;

                while(numset.find(currentNum+1) != numset.end()){
                    currentNum++;
                    streak++;
                }
                best = max(best, streak);
            }
        }
        return best;
    }
};