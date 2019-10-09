#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int n = prices.size() - 1;
        int i = 0, buy = 0, sell = 0;
        while(i < n)
        {
            while(i < n && prices[i] >= prices[i+1]) i++;
                buy = prices[i];
            while(i < n && prices[i] < prices[i+1]) i++;
                sell = prices[i];
            sum += sell - buy;
        }
        return sum;
    }
};

// 按照递增计算
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            sum += max(prices[i] - prices[i-1], 0);
        }
        return sum;
    }
};
*/


int main()
{
    vector<int> prices = {6,1,3,2,4,7};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}
