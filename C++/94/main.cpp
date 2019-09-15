#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ∑«µ›πÈ–¥∑®
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        while(root || !st.empty())
        {
            while(root)
            {
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            st.pop();
            res.push_back(root -> val);
            root = root -> right;
        }
    }
};

// µ›πÈ–¥∑®
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    void inorder(TreeNode* root, vector<int>& res)
    {
        if(root == NULL)
            return ;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};
*/

int main()
{

    return 0;
}
