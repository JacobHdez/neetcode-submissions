#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_set<string> checked;

        vector<vector<string>> results;

        for ( int i = 0; i < strs.size(); ++i ) {
            if ( checked.count(strs[i]) > 0 )
                continue;

            vector<string> curr;
            curr.push_back(strs[i]);
            checked.insert(strs[i]);

            for ( int j = i+1; j < strs.size(); ++j ) {
                if ( is_anagram(strs[i], strs[j]) ) {
                    curr.push_back(strs[j]);
                    checked.insert(strs[j]);
                }
            }

            results.push_back(curr);
        }
        return results;
    }

    bool is_anagram( string &s1, string &s2 ) {
        if ( s1.size() != s2.size() ) return false;

        unordered_map<char, int> s1_map, s2_map;
        for ( int i = 0; i < s1.size(); ++i ) {
            s1_map[s1[i]]++;
            s2_map[s2[i]]++;
        }

        for ( auto &s1_it : s1_map ) {
            auto s2_it = s2_map.find(s1_it.first);

            if ( s2_it == s2_map.end() ) return false;
            if ( s1_it.second != s2_it->second ) return false;
        }

        return true;
    }
};
