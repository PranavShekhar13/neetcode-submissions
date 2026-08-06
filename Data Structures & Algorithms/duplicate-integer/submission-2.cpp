class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return false;

    unordered_set<int> hash;

    for(int &num:nums){
        if(hash.find(num) != hash.end()){
            return true;
        }
        hash.insert(num);
    }

    return false;
    }
};