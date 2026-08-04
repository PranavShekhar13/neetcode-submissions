class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m;
        int right = 0;
        while(left<(m+n) && right<n){
            swap(nums1[left], nums2[right]);
            left++;
            right++;
        }
        sort(nums1.begin(),nums1.end());
    }
};