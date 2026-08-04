class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<int> hash(256);
        int left = 0, right = 0, maxLength = 0;

        while(right<n){

            while(hash.find(s[right]) != hash.end()){
                hash.erase(s[left]);
                left++;
            }
            
            hash.insert(s[right]);
            maxLength = max(maxLength,right-left+1);
            right++; 
        }

        return maxLength;
    }
};
