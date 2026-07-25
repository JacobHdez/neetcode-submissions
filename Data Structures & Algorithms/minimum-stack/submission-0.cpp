class MinStack {
public:
    vector<int> m_stack;
    size_t m_minpos;

    MinStack() {
        m_minpos = 0;
    }
    
    void push(int val) {
        m_stack.push_back(val);
        if ( m_stack.back() < m_stack[m_minpos] )
            m_minpos = m_stack.size() - 1;
    }
    
    void pop() {
        if ( m_stack.size() == 0 ) return;

        m_stack.pop_back();
        if ( m_minpos == m_stack.size() )
            m_minpos = distance(m_stack.begin(), min_element(m_stack.begin(), m_stack.end()));
    }
    
    int top() {
        return m_stack.back();
    }
    
    int getMin() {
        return m_stack[m_minpos];
    }
};
