class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for ( const string &str : strs )
            enc += to_string(str.size()) + '#' + str;
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        int j = 0;

        while (i < s.size()) {
            j = i;
            while ( s[j] != '#' )
                j++;

            int size = stoi(s.substr(i, j-i));
            i = j + 1;
            strs.push_back( s.substr(i, size) );

            i = i + size;
        }

        return strs;
    }
};
