#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ≤„–Ú±È¿˙bfs
class Solution{
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while(!que.empty())
        {
            int size = que.size();
            depth++;
            for(int i = 0; i < size; ++i)
            {
                TreeNode* tmp = que.front();
                que.pop();
                if(tmp->left != NULL)
                    que.push(tmp->left);
                if(tmp->right != NULL)
                    que.push(tmp->right);
            }
        }
        return depth;
    }
};

// µ›πÈ∞Ê±æ
/*
class Solution{
public:
    int maxDepth(TreeNode* root) {
       return root == NULL ? 0 : max(maxDepth(root->left),maxDepth(root->right)) +1;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        return max(left,right);
    }
};
*/

int main()
{

    return 0;
}
