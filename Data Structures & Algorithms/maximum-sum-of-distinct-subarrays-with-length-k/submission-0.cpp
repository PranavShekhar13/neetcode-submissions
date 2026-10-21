class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long windowSum = 0;
        long long maxSum = 0;
        int start = 0;
        int n = nums.size();

        unordered_map<int, int> freqMap;

        for(int end = 0; end<n; end++){
            windowSum += nums[end];
            freqMap[nums[end]]++;

            if( (end-start+1) == k){
                if(freqMap.size() == k){
                    maxSum = max(windowSum, maxSum);
                }

                windowSum -= nums[start];
                freqMap[nums[start]]--;
                if(freqMap[nums[start]] == 0){
                    freqMap.erase(nums[start]);
                }
                start++;
            }

        }
        return maxSum;
    }
};
