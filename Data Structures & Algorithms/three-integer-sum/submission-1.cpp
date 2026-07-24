class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for ( int fixed = 0; fixed < (int)nums.size(); ++fixed ) {
            if ( fixed > 0 && nums[fixed] == nums[fixed-1] )
                continue;
            int l = fixed + 1;
            int r = (int)nums.size() - 1;

            while ( l < r ) {
                int sum = nums[fixed] + nums[l] + nums[r];
                if ( sum == 0 ) {
                    triplets.push_back({nums[fixed], nums[l], nums[r]});
                    while ( l < r && nums[l] == nums[l+1] ) l++;
                    while ( r > l && nums[r] == nums[r-1] ) r--;
                    l++; r--;
                }
                else if ( sum < 0 ) l++;
                else r--;
            }
        }

        return triplets;
    }
};
