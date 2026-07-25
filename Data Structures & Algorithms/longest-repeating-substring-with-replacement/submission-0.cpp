class Solution {
public:
    int characterReplacement(string s, int k) {
        int c_count[26] = {0};
        int max_f = 0;
        int max_len = 0;

        int l = 0;
        for ( int r = 0; r < s.size(); ++r ) {
            c_count[s[r] - 'A']++;
            if ( c_count[s[r] - 'A'] > max_f )
                max_f = c_count[s[r] - 'A'];

            if ( r - l + 1 - max_f > k )
                c_count[s[l++] - 'A']--;

            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};
