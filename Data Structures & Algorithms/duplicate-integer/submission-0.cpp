#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;

        for ( int n : nums ) {
            if ( nums_set.count(n) > 0 ) return true;
            nums_set.insert(n);
        }
        return false;
    }
};