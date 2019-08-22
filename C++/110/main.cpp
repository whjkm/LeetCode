#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ���ú���������ٽ����ظ�����
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return judge(root, depth);
    }
    bool judge(TreeNode* root, int& depth)
    {
        if(root == NULL)
           return true;
        int left = 0;
        int right = 0;
        if(judge(root->left,left) && judge(root->right, right))
        {
            if(abs(left-right) > 1)
                return false;
            depth = max(left, right) + 1;
            return true;
        }
        return false;
    }
};

// �ݹ�棬�ֱ�������������ĸ߶ȣ��ֱ��ж����������Ƿ���ƽ�������
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int left = MaxDepth(root->left);
        int right = MaxDepth(root->right);
        if(abs(left-right) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int MaxDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return max(MaxDepth(root->left),MaxDepth(root->right))+1;
    }
};

int main()
{

    return 0;
}
