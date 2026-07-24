class Solution {
public:
    int maxArea(vector<int>& heights) {
        int water = 0;
        int max_water = water;
        int l = 0;
        int max_l = l;
        int r = heights.size() - 1;
        int max_r = r;

        while ( l < r ) {
            water = (r - l) * min(heights[l], heights[r]);
            if ( water > max_water ) {
                max_water = water;
                max_l = l;
                max_r = r;
            }

            int diff = heights[l] - heights[r];
            if ( diff == 0 ) {
                l++; r--;
            }
            else if ( diff > 0 )
                r--;
            else
                l++;
        }

        return (max_r - max_l) * min(heights[max_l], heights[max_r]);
    }
};
