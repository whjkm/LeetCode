#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    if (str.empty()) return 0;
    int i = 0, sign = 1;
    while (i + 1 < str.size() && isspace(str[i])) ++i;
    long res = 0;
    if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
    while (i < str.size()) {
        if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
        else return res * sign;
        if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
    }
    return res * sign;
}
};



/*
int itoa(int n, char s[])
{
      int i;
      int j;
      int sign;
      sign = n;    //记录符号
      if(sign < 0)
      {
        n = -n;  //变为正数处理
      }
      i = 0;
      do{
          s[i++] = n % 10 + '0';  //取下一个数字
      }while((n /= 10) > 0);
      if(sign < 0 )
      {
          s[i++] = '-';
          s[i] = '\0';
      }
      for(j = i-1; j >= 0; j-- )
      {
          printf("%c", s[j]);
      }
      return 0;
}
*/

int myatoi(const char *str)
{
    int temp = 0;
    const char *ptr = str;
    if(*str == '-' || *str == '+')
        str++;
    while(*str != 0)
    {
        if(*str < '0' || *str > '9')
        {
            break;
        }
        temp = temp * 10 + (*str - '0');
        str++;
    }
    if(*ptr == '-')
        temp = -temp;
    return temp;
}

void itoa(int n, char *str)
{
    char buf[20] = "";
    int i = 0, len = 0;
    int sign = n;
    if(sign < 0)
    {
        n = -n;
    }
    while(n)
    {
        buf[i++] = (n % 10) + '0';
        n /= 10;
    }
    if(sign < 0)
    {
        buf[i++] = '-';
    }
    buf[i] = '\0';
    int k = 0;
    for(int j = i-1; j >=0; j--)
    {
        str[k++] = buf[j];
    }
    str[k] = '\0';
}


int check_sys()
 {
  int i = 1;
  //返回1小端
  //返回0是大端
  return (*(char *)&i);
 }
/*
int check_sys()
{
   union{
         int i;
         char c;
        }un;
    un.i = 1;
    return un.c;//大端返回0，小端返回1.
}
*/
int main()
{
    int n;
    char p[20];
    cout << check_sys() << endl;
    //cin >> n;
    //my_itoa(n,p);
    //itoa(n, p);
    //cout << p << endl;
    //cout << myatoi("20") << endl;
    return 0;
}
