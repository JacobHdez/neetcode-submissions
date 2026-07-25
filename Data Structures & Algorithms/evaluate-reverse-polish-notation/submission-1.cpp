class Solution {
public:
    stack<int> m_stack;

    bool is_number( const string &s ) {
        if ( s.size() == 1 ) {
            switch ( s[0] ) {
                case '+':
                case '-':
                case '*':
                case '/':
                    return false;
            }
        }
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        for ( string token : tokens ) {
            if ( is_number(token) ) {
                m_stack.push(stoi(token));
                continue;
            }
            cout << m_stack.size() << endl;
            
            int r = m_stack.top();
            m_stack.pop();
            int l = m_stack.top();
            m_stack.pop();

            switch ( token[0] ) {
                case '+':
                    m_stack.push( l + r );
                    break;
                case '-':
                    m_stack.push( l - r );
                    break;
                case '*':
                    m_stack.push( l * r );
                    break;
                case '/':
                    m_stack.push( l / r );
                    break;
            }
        }

        return m_stack.top();
    }
};
