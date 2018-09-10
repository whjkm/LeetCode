#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1; i<=n; i++){
            if(i % 3 == 0 && i % 5 == 0){
                res.push_back("FizzBuzz");
            }else if(i % 3 == 0){
                res.push_back("Fizz");
            }else if(i % 5 == 0){
                res.push_back("Buzz");
            }else{
                stringstream stream;
                stream<<i;
                //string temp = to_string(i);
                string string_temp=stream.str();
                res.push_back(string_temp);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> temp;
    temp = s.fizzBuzz(15);
    for(int i=0; i<15; i++)
    cout << temp[i] <<endl;
    return 0;
}
