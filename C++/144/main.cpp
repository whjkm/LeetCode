#include <iostream>
#include <stack>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// morris, 记录中序遍历的前驱
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while(root)
        {
            if(root->left)
            {
                TreeNode * pre = root -> left;
                while(pre -> right && pre -> right != root)
                {
                    pre = pre -> right;
                }
                if(!pre -> right)
                {
                    pre -> right = root;
                    res.push_back(root -> val);
                    root = root -> left;
                }
                else
                {
                    pre -> right = NULL;
                    root = root -> right;
                }
            }
            else
            {
                res.push_back(root -> val);
                root = root -> right;
            }
        }
        return res;
    }
};
// 非递归，栈存储右子节点
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        while(root || !st.empty())
        {
            if(root)
            {
                res.push_back(root->val);
                if(root -> right)
                    st.push(root->right);
                root = root -> left;
            }
            else
            {
                root = st.top();
                st.pop();
            }
        }
        return res;
    }
};
*/

//递归
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    void preorder(TreeNode* root, vector<int> &res)
    {
        if(root == NULL)
            return ;
        res.push_back(root->val);
        preorder(root -> left, res);
        preorder(root -> right, res);
    }
};
*/


int main()
{

    return 0;
}
