class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int longestStreak = 0;
        for(auto &num:hash){
            if(hash.find(num-1) == hash.end()){
                int currentNum = num;
                int streak = 1;
                while(hash.find(currentNum + 1) != hash.end()){
                    currentNum++;
                    streak++;
                }
            longestStreak = max(longestStreak, streak);
            }
        }
        return longestStreak;
    }
};
