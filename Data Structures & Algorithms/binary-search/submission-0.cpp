class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while ( l <= r ) {
            int t = l + (int)((r - l) / 2.0);
            if ( nums[t] > target ) r = t-1;
            else if ( nums[t] < target ) l = t+1;
            else return t;
        }

        return -1;
    }
};
