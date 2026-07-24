// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> steps;
        if ( pairs.empty() )
            return steps;

        steps.push_back(pairs);
        for ( size_t i = 1; i < pairs.size(); ++i ) {

            for ( int j = i; j > 0; --j ) {
                if ( pairs[j].key < pairs[j-1].key ) {
                    Pair temp(pairs[j-1].key, pairs[j-1].value);
                    pairs[j-1].key = pairs[j].key;
                    pairs[j-1].value = pairs[j].value;
                    pairs[j].key = temp.key;
                    pairs[j].value = temp.value;
                }
                continue;
            }
            steps.push_back(pairs);
        }

        return steps;
    }
};
