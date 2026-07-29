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

        for ( size_t i = 0; i < n; ++i ) {
            position[i] = paired[i].first;
            speed[i] = paired[i].second;
        }

        stack<float> s;
        s.push( (float)(target - position[0]) / (float)speed[0] );
        for ( size_t i = 1; i < n; ++i  ) {
            float time = (float)(target - position[i]) / (float)speed[i];

            if ( time > s.top() )
                s.push(time);
        }

        return s.size();
    }
};
