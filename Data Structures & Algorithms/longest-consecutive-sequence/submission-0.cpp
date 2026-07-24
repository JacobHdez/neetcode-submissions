class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_count = 0;

        for ( const int &num : nums ) {
            if ( nums_set.count(num-1) == 0 ) {
                int count = 1;

                int next = num + 1;
                while ( nums_set.count(next) > 0 ) {
                    next++;
                    count++;
                }

                if ( count > max_count )
                    max_count = count;
            }
        }

        return max_count;
    }
};
