class Solution {
public:
    int maxArea(vector<int>& heights) {
        int R = heights.size()-1;
        int maxArea = 0;
        int L = 0;
        while(L<R){
            int area = (R-L) * min(heights[L], heights[R]);
            maxArea = max(area, maxArea);

            if(heights[L]<=heights[R]) L++;
            else R--;
        }

        return maxArea;
    }
};
