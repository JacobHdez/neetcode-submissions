#include <vector>

struct Node {
    int m_value;
    Node *m_next;

    Node() {
        m_value = 0;
        m_next = nullptr;
    }
    Node ( int val, Node *next = nullptr ) {
        m_value = val;
        m_next = next;
    }
};

class LinkedList {
private:
    Node *m_root;
    int m_size;

public:
    LinkedList() {
        m_root = nullptr;
        m_size = 0;
    }

    int get(int index) {
        if ( index >= m_size || index < 0 ) return -1;
        if ( index == 0 ) return m_root->m_value;

        Node *curr = m_root->m_next;
        int i = 1;
        while ( curr != nullptr ) {
            if ( index == i ) return curr->m_value;
            curr = curr->m_next;
            i++;
        }
        return -1;
    }

    void insertHead(int val) {
        if ( m_root == nullptr ) {
            m_root = new Node(val);
            m_size++;
            return;
        }

        Node *new_root = new Node(val, m_root);
        m_root = new_root;
        m_size++;
    }
    
    void insertTail(int val) {
        if ( m_root == nullptr ) {
            m_root = new Node(val);
            m_size++;
            return;
        }

        Node *curr = m_root;
        while ( curr->m_next != nullptr ) {
            curr = curr->m_next;
        }

        Node *new_node = new Node(val);
        curr->m_next = new_node;
        m_size++;
    }

    bool remove(int index) {
        if ( index < 0 || index >= m_size ) return false;

        if ( index == 0 ) {
            Node *del_node = m_root;
            m_root = m_root->m_next;
            delete del_node;
            m_size--;
            return true;
        }

        Node *curr = m_root;
        int i = 1;

        while ( i < index ) {
            curr = curr->m_next;
            i++;
        }

        Node *del_node = curr->m_next;
        curr->m_next = del_node->m_next;
        delete del_node;
        m_size--;

        return true;
    }

    vector<int> getValues() {
        vector<int> values(m_size);

        Node *curr = m_root;
        int i = 0;
        while ( curr != nullptr ) {
            values[i++] = curr->m_value;
            curr = curr->m_next;
        }

        return values;
    }
};
