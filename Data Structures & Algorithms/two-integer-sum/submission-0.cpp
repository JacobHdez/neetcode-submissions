#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> reminder;
        vector<int> index(2);

        for ( int i = 0; i < nums.size(); ++i ) {
            int r = target - nums[i];
            
            auto r_it = reminder.find(r);
            if ( r_it == reminder.end() )
                reminder[nums[i]] = i;
            else {
                if ( nums[i] + r_it->first == target ) {
                    index[0] = r_it->second;
                    index[1] = i;
                    return index;
                }
            }
        }
        return index;
    }
};
