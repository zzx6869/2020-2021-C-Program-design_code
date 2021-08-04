//BFS version
#include<iostream>
#include<string>
int m, n, classroom[51][51][5], flag[51][51],Max=1;
int num = 0, Des[4][2] = { {0,-1}, {-1,0} ,{0,1} ,{1,0} }, xx[2601], yy[2601];
int roomsize[2601];
using namespace std;
void bfs(void)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!flag[i][j])
			{
				flag[i][j] = ++num;
				xx[1] = i;
				yy[1] = j;
				int front = 0, near = 1, sum = 1;;
				while (front < near)
				{
					front++;
					int _x, _y;
					for (int k = 0; k <= 3; k++)//if write {int k=0;while(k++=3){}},false
					{
						_x = xx[front] + Des[k][0];
						_y = yy[front] + Des[k][1];
						if (_x > 0 && _y > 0 && _x <= n && _y <= m && !flag[_x][_y] && !classroom[xx[front]][yy[front]][k])
						{
							flag[_x][_y] = num;
							sum++;
							xx[++near] = _x;
							yy[near] = _y;
						}
					}
				}
				roomsize[num] = sum;
				Max = max(sum, Max);
			}
		}
	}
}
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int count;
			cin >> count;
			if (count & 1)classroom[i][j][0] = 1;//weat
			if (count & 2)classroom[i][j][1] = 1;//nouth
			if (count & 4)classroom[i][j][2] = 1;//east
			if (count & 8)classroom[i][j][3] = 1;//south
		}
	}
	bfs();
	cout << num << endl << Max << endl;
	int MAX = Max;
	int x = 1, y = 1; char position = '/0';
	for (int k = 1; k <= m; k++)
	{
		for (int i = n; i > 0; i = i - 1)
		{
			if (flag[i][k] != flag[i - 1][k])//nouth
			{
				if (roomsize[flag[i][k]] + roomsize[flag[i - 1][k]] > Max)
				{
					x = i, y = k;
					Max = roomsize[flag[i][k]] + roomsize[flag[i - 1][k]];
					position = 'N';
				}
			}
			if (flag[i][k] != flag[i][k + 1])
			{
				if (roomsize[flag[i][k]] + roomsize[flag[i][k + 1]] > Max)
				{
					x = i, y = k;
					Max = roomsize[flag[i][k]] + roomsize[flag[i][k + 1]];
					position = 'E';
				}
			}
		}
	}
	cout << Max << endl << x << " " << y << " " << position << endl;
}
