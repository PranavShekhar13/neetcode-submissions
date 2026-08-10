class Solution {
public:
    void sortColors(vector<int>& nums) {

        int count0 = 0, count1 = 0, count2 = 0;
        
        for(int &num: nums){
            if(num == 0) count0++;
            if(num == 1) count1++;
            if(num == 2) count2++;
        }

        int index = 0;

        while(count0>0){
            nums[index++] = 0;
            count0--;
        }
        while(count1>0){
            nums[index++] = 1;
            count1--;
        }
        while(count2>0){
            nums[index++] = 2;
            count2--;
        }

    }
};