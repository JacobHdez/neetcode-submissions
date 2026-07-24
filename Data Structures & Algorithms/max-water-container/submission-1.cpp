class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;
        int l = 0;
        int r = heights.size() - 1;

        while ( l < r ) {
            int water = (r - l) * min(heights[l], heights[r]);
            if ( water > max_water )
                max_water = water;

            int diff = heights[l] - heights[r];
            if ( diff == 0 ) {
                l++; r--;
            }
            else if ( diff > 0 )
                r--;
            else
                l++;
        }

        return max_water;
    }
};
