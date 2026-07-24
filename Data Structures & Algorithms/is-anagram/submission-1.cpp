#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map, t_map;
        for ( char c : s ) s_map[c]++;
        for ( char c : t ) t_map[c]++;

        if ( s_map.size() != t_map.size() ) return false;
        for ( auto &p : s_map ) {
            unordered_map<char, int>::const_iterator t_it = t_map.find(p.first);

            if ( t_it == t_map.end() ) return false;
            if (p.second != t_it->second) return false;
        }
        return true;
    }
};
