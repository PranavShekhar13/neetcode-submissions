class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0;
        int R = heights.size()-1;
        int maxArea = 0;
        while(L<R){
            int H = min(heights[L],heights[R]);
            int W = R-L;
            int area = H*W;
            maxArea = max(maxArea, area);

            if(heights[L]<heights[R]){
                L++;
            }
            else{
                R--;
            }
        }
        return maxArea;
    }
};
