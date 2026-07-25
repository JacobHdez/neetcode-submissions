class Solution {
public:
    int freq_s1[26] = {0};
    int freq_s2[26] = {0};

    bool eq_arr() {
        for ( int i = 0; i < 26; ++i ) {
            if ( freq_s1[i] != freq_s2[i] )
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        

        for ( int i = 0; i < s1.size(); ++i ) {
            freq_s1[s1[i] - 'a']++;
            freq_s2[s2[i] - 'a']++;
        }
        if ( eq_arr() )
            return true;

        for ( int i = s1.size(); i < s2.size(); ++i ) {
            freq_s2[s2[i] - 'a']++;
            freq_s2[s2[i - s1.size()] - 'a']--;

            if ( eq_arr() )
                return true;
        }

        return false;
    }
};
