#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) return false;

        unordered_map<char, int> s_map, t_map;
        for ( int i = 0; i < s.size(); ++i ) {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }

        for ( auto &p : s_map ) {
            unordered_map<char, int>::const_iterator t_it = t_map.find(p.first);

            if ( t_it == t_map.end() ) return false;
            if (p.second != t_it->second) return false;
        }
        return true;
    }
};
