class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());
        int l, r;

        l = 0;
        while ( l < height.size() ) {
            while ( l < height.size() && height[l] == 0 ) ++l;
            r = l + 1;

            while ( r < height.size() && height[r] < height[l] ) {
                prefix[r] = height[l] - height[r];
                r++;
            }
            l = r;
        }

        r = height.size() - 1;
        while ( r >= 0 ) {
            while ( r >= 0 && height[r] == 0 ) --r;
            l = r - 1;

            while ( l >= 0 && height[l] < height[r] ) {
                suffix[l] = height[r] - height[l];
                l--;
            }
            r = l;
        }

        int count = 0;
        for ( int i = 0; i < height.size(); ++i ) {
            count += min(prefix[i], suffix[i]);
        }

        return count;
    }
};
