class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        size_t n = position.size();

        std::vector<std::pair<int, int>> paired(n);
        for ( size_t i = 0; i < n; ++i )
            paired[i] = { position[i], speed[i] };

        std::sort(
            paired.begin(), paired.end(),
            []( std::pair<int, int> &l, std::pair<int, int> &r ) { return l.first > r.first; }
        );

        stack<float> s;
        s.push( (float)(target - paired[0].first) / (float)paired[0].second );
        for ( size_t i = 1; i < n; ++i  ) {
            float time = (float)(target - paired[i].first) / (float)paired[i].second;

            if ( time > s.top() )
                s.push(time);
        }

        return s.size();
    }
};
