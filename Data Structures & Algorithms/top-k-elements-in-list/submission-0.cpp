class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for ( const int &num : nums )
            freq[num]++;
        
        vector<pair<int,int>> pairs(freq.begin(), freq.end());
        sort(
            pairs.begin(), pairs.end(),
            []( const pair<int,int>& l, const pair<int,int>& r ) {
                if ( l.second > r.second ) return true;
                else if ( l.second == r.second )
                    return l.first < r.first;
                return false;
            }
        );

        vector<int> top_k(k);
        for ( int i = 0; i < k; ++i )
            top_k[i] = pairs[i].first;
        
        return top_k;
    }
};
