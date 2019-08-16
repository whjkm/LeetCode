#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/***
经典回溯题：三要素，选择（Options）,限制（Restraints）,结束条件（Termination）
选择：1.加左括号； 2.加右括号
限制：1.左括号用完，就不能加左括号了；
      2.如果出现的左括号和右括号一样多，就不能加右括号了。
结束条件： 左右括号同时用完。
结束后的正确性:
       左右括号同时用完，一定是正解。
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
