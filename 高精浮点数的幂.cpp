#include<iostream>
#include<string>
#include <sstream>
using namespace std;
int na[1000000], nb[1000000], c[20000000],lenc;
//重载乘号
string operator *(string str1, string str2)
{
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    string str;
    int x = str1.size(), y = str2.size();
    long long k = 0, pre = 0;
    for (int i = 1; i <= str1.size() + str2.size() - 1 || k != 0; i++) {
        for (int j = 1; j <= i; j++) {
            if (j - 1 < 0 || j - 1 > x - 1 || i - j<0 || i - j>y - 1)continue;
            pre += (str1[j - 1] -'0') * (str2[i - j] -'0');
        }
        str.push_back((pre + k) % 10 +'0');
        k = (pre + k) / 10;
        pre = 0;
    }
    reverse(str.begin(), str.end());
    return str;
}//三
 
int main()
{
    string F, F1,F2;
    int n, i;
    int k,t;
    while (cin >> F >> n)
    {
        k = 0;
        i = 0;
        if (F[0] =='0')
        {
            for (i = 0; (i < F.size()) && F[i] =='0'; )
            {
                i++;
            }
        }//一
        for (int j = 0; j < F.size() - i; j++)
        {
            if (F[i] =='.'&&j==0)
            {
 
                j++;
                k = F.size() -i - 1;
            }
            if (F[i + j] =='.')
            {
                k = F.size() - i - j - 1;
                j++;
                if (i + j == F.size())
                    break;
            }
            F1.push_back(F[i + j]);
        }//二
        F2 = F1;
        for (int q = 1; q < n; q++)
        {
            F2 = F1 * F2;
        }//四
        int l4 = F2.size();
        reverse(F2.begin(), F2.end());
        for (t = 0; F2[t] =='0' && t < n * k; t++)
        {
        }
        reverse(F2.begin(), F2.end());//五
        for (int i = 0; i < l4-t; i++)
        {
            if ((i == l4 - k*n)&&(l4-k*n>0))
            {
                cout <<".";
                 
            }
            else if (l4 - k * n <= 0&&i==0)
            {
                cout <<".";
                for (int m = 0; m < k*n-l4; m++)
                {
                    cout << 0;
                }
            }
            cout << F2[i];
        }//六
        cout << endl;
        F.clear();//记得清空
        F1.clear();
    }
}
