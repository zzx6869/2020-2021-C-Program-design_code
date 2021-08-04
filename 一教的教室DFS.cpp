#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
#pragma GCC optimize(0)
int n = 0, m = 0, room[61][61][4] = { 0 }, flag[61][61]{ 0 }, s = 0, maxn = 1, ans = 0, xx = 0, yy = 0, roomsize[2600] = { 0 };
char position='a';
int dfs(int x, int y)
{
    if (flag[x][y]!= 0|| x <= 0 || y <= 0 || x > n || y > m)
    {
        return 0;
    }
    ans++;
    flag[x][y] = s + 1;
    if (room[x][y][0] == 0 && !(flag[x][y+1] != 0 || x <= 0 || y <= 0 || x > n || y > m)) {//east
        dfs(x, y + 1);
    }
    if (room[x][y][1] == 0 && !(flag[x+1][y] != 0 || x <= 0 || y <= 0 || x > n || y > m)) {//south
        dfs(x + 1, y);
    }
    if (room[x][y][2] == 0 && !(flag[x][y - 1] != 0 || x <= 0 || y <= 0 || x > n || y > m)) {//west
        dfs(x, y - 1);
    }
    if (room[x][y][3] == 0 && !(flag[x-1][y] != 0 || x <= 0 || y <= 0 || x > n || y > m)) {//nouth
        dfs(x - 1, y);
    }
}
int main()
{
    cin >> m >> n;
    yy = 10000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s;
            if (s & 1) room[i][j][2] = 1;
            if (s & 2) room[i][j][3] = 1;
            if (s & 4) room[i][j][0] = 1;
            if (s & 8) room[i][j][1] = 1;
        }
    }
    s = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
        {
            ans = 0;
            if (flag[i][j] == 0) {
                dfs(i, j);
                s++;
                roomsize[s] = ans;
            }
            maxn = max(maxn, ans);
        }
    }
    ans = 0;
    cout << s << endl << maxn << endl;
    int Max = maxn;

    for (int k = 1; k <= m; k++)
    {
        for (int i = n; i > 0; i = i - 1)
        {
            if (flag[i][k] != flag[i - 1][k])//nouth
            {
                if (roomsize[flag[i][k]] + roomsize[flag[i - 1][k]] > Max)
                {
                    xx = i, yy = k;
                    Max = roomsize[flag[i][k]] + roomsize[flag[i - 1][k]];
                    position = 'N';
                }
            }
            if (flag[i][k] != flag[i][k + 1])
            {
                if (roomsize[flag[i][k]] + roomsize[flag[i][k + 1]] > Max)
                {
                    xx = i, yy = k;
                    Max = roomsize[flag[i][k]] + roomsize[flag[i][k + 1]];
                    position = 'E';
                }
            }
        }
    }
    cout << Max << endl << xx << " " << yy << " " << position << endl; //输出
    return 0;
}
