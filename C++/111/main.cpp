#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS���������,�ҵ���һ��Ҷ�ӽڵ�Ĳ���
class Solution {
public:
    int minDepth(TreeNode* root) {
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
                if(tmp->left != NULL)
                    que.push(tmp->left);
                if(tmp->right != NULL)
                    que.push(tmp->right);
                que.pop();
                // �ҵ���һ��Ҷ�ӽڵ㣬����
                if(tmp->left == NULL && tmp->right == NULL)
                    return depth;
            }
        }
        return -1;
    }
};

// �ݹ�
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (min(left, right) ? min(left, right) : max(left, right)) + 1;
    }
};


int main()
{

    return 0;
}
