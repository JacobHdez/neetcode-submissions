class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r] - target;
            if ( sum < 0 ) l++;
            else if ( sum > 0 ) r--;
            else break;
        }

        return {l+1, r+1};
    }
};
