#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/***
��������⣺��Ҫ�أ�ѡ��Options��,���ƣ�Restraints��,����������Termination��
ѡ��1.�������ţ� 2.��������
���ƣ�1.���������꣬�Ͳ��ܼ��������ˣ�
      2.������ֵ������ź�������һ���࣬�Ͳ��ܼ��������ˡ�
���������� ��������ͬʱ���ꡣ
���������ȷ��:
       ��������ͬʱ���꣬һ�������⡣
***/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS(res, "", n, n);
        return res;
    }
    void DFS(vector<string> &res, string str, int left, int right)
    {
        if(left == 0 && right == 0)
        {
            res.push_back(str);
            return ;
        }
        if(left > right)
        {
            return ;
        }
        if(left > 0)
        {
            DFS(res, str + "(", left - 1, right);
        }
        if(right > 0)
        {
            DFS(res, str + ")", left, right - 1);
        }
    }
};

int main()
{
    Solution s;
    vector<string> res;
    res = s.generateParenthesis(3);
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
