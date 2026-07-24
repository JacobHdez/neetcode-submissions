class Solution {
public:
    bool isValid(string s) {
        if ( s.size() % 2 != 0 )
            return false;
        
        stack<char> c_stack;
        for ( const char &c : s ) {
            if ( c == '(' || c == '[' || c == '{' )
                c_stack.push(c);
            else {
                if ( c_stack.empty() ) return false;

                char l = c_stack.top();
                c_stack.pop();
                if ( c == ')' )
                    if ( l != '(' )
                        return false;
                if ( c == ']' )
                    if ( l != '[' )
                        return false;
                if ( c == '}' )
                    if ( l != '{' )
                        return false;
            }
        }

        return c_stack.empty();
    }
};
