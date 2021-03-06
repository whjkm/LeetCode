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

// morris
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        while(root)
        {
            if(root->left)
            {
                TreeNode* pre = root -> left;
                while(pre->right && pre->right != root)
                {
                    pre = pre -> right;
                }
                if(!pre->right)
                {
                    pre->right = root;
                    root = root -> left;
                }
                else
                {
                    pre->right = NULL;
                    res.push_back(root->val);
                    root = root -> right;
                }
            }
            else
            {
                res.push_back(root->val);
                root = root -> right;
            }
        }
        return res;
    }
};

// �ǵݹ�д��
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(root || !st.empty())
        {
            while(root)
            {
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root -> right;
        }
        return res;
    }
};
*/

// �ݹ�д��
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
