class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size());

        stack<int> s;
        for ( int i = 0; i < days.size(); ++i ) {
            while ( !s.empty() && temperatures[i] > temperatures[s.top()] ) {
                int index = s.top();
                s.pop();

                days[index] = i - index;
            }
            s.push(i);
        }

        return days;
    }
};
