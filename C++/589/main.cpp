#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// 非递归
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* cur = st.top();
            st.pop();
            res.push_back(cur -> val);
            for(int i = cur->children.size() - 1; i >=0; --i)
            {
                if(cur->children[i] != NULL)
                    st.push(cur->children[i]);
            }
        }
        return res;
    }
};


// 递归
/*
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        pre(root, res);
        return res;
    }
    void pre(Node *root, vector<int> &res)
    {
        if(root == NULL)
            return ;
        res.push_back(root->val);
        for(int i = 0; i < root->children.size(); ++i)
        {
            pre(root->children[i],res);
        }
    }
};
*/

int main()
{

    return 0;
}
