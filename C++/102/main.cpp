#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<int> tmp;
        queue<TreeNode*> qu;
        qu.push(root);
        int len = 1;
        while(!qu.empty())
        {
            TreeNode* top = qu.front();
            qu.pop();
            tmp.push_back(top->val);
            if(top -> left)
                qu.push(top->left);
            if(top -> right)
                qu.push(top->right);
            if(--len == 0)
            {
                res.push_back(tmp);
                tmp.clear();
                len = qu.size();
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
    void dfs(TreeNode* root, int depth, vector<vector<int>> &res)
    {
        if(root == NULL)
            return ;
        if(res.size() == depth)
            res.push_back(vector<int>());

        res[depth].push_back(root->val);
        dfs(root->left, depth+1, res);
        dfs(root->right, depth+1, res);
    }
};
*/

// 使用两个队列
/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode *> qu;
        vector<int> tmp;
        queue<TreeNode *> nodes;
        qu.push(root);
        while(!qu.empty())
        {
            TreeNode *top = qu.front();
            tmp.push_back(top->val);
            qu.pop();
            if(top -> left)
                nodes.push(top->left);
            if(top -> right)
                nodes.push(top->right);
            if(qu.empty())
            {
                qu.swap(nodes);
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};
*/
int main()
{

    return 0;
}
