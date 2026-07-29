/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if ( root == nullptr ) return 0;

        int max_d = 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        while ( !s.empty() ) {
            auto curr = s.top();
            s.pop();

            if ( curr.second > max_d )
                max_d = curr.second;

            if ( curr.first->left != nullptr ) s.push({curr.first->left, curr.second + 1});
            if ( curr.first->right != nullptr ) s.push({curr.first->right, curr.second + 1});
        }

        return max_d;
    }
};
