#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//先前序遍历这棵树的结点，如果遍历到的结点有子结点，就交换它的两个子结点，
//当交换完所有非叶子结点的左右子结点之后，就得到了树的镜像。
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       if(!root) return true;
       return helper(root->left, root->right);
    }
    bool helper(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return true;
        if(!left || !right) return false;
        return (left -> val == right -> val) &&
                helper(left->left, right->right) &&
                helper(left->right, right->left);
    }
};
*/
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if(!root) return true;
        stack<TreeNode*> sl, sr;
        sl.push(root);
        sr.push(root);
        TreeNode *lp = root->left, *rp = root->right;
        while(lp || !sl.empty() || rp || !sr.empty())
        {
            if((!lp && rp) || (lp && !rp)) return false;
            if(lp && rp)
            {
                if(lp->val != rp->val) return false;
                sl.push(lp);
                sr.push(rp);
                lp = lp->left;
                rp = rp->right;
            }
            else
            {
                lp = sl.top()->right;
                rp = sr.top()->left;
                sl.pop();
                sr.pop();
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
