#include<stdio.h>
#include<math.h>
int parent[10000] = { 0 };
int find_root(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find_root(parent[x]);
	}
} //寻找并返回根节点 
int unit(int x, int y) {
	int x_root = find_root(x);
	int y_root = find_root(y);
	if (x_root == y_root) {
		return 0;
	}
	else {
		parent[x_root] = y_root;
		return 1;
	}
}//返回1表示合并成功，返回0表示合并失败，且只有要合并的两个点本来在一起时才会返回0； 
int main() {
	int n, m, i, j, o, w, num, max, MAX, M = 0;
	char dir;
	scanf("%d%d", &m, &n);
	w = m * n;
	int room[3000], root[3000] = { 0 };//parent数组放前驱节点，room数组记录题目数据，root数组记载有多大； 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &room[i * n + m]);//将二维的转化为一维的，并记录数据 
		}
	}//因为变成了一维且自上到下自左到右讨论，所以之后的"case"只考虑东和南 
	for (i = 0; i < w; i++) {
		switch (room[i])
		{
		case 0:
		case 1:
		case 2:
		case 3:
		{
			if (i + m <= m * n)//南
			{
				unit(i, i + m);
			}
			if (i % m != 0)//东
			{
				unit(i, i + 1);
			}
			break;
		}
		case 4:
		case 5:
		case 6:
		case 7:
		{
			if (i + m <= m * n)//南
			{
				unit(i, i + m);
			}
			break;
		}
		case 8:
		case 9:
		case 10:
		case 11:
		{
			if (i % m != 0)//东
			{
				unit(i, i + 1);
			}
			break;
		}
		default:
			break;
		}
	}

	for (i = 0; i < w; i++)
	{
		root[find_root(i)]++;//统计每个教室有多大 
	}
	num = 0; max = 0;
	for (i = 0; i < w; i++)
	{
		if (root[i] > 0) {
			num++;
		}
		if (root[i] >= max) {
			max = root[i];
		}
	}//统计房间数并找到最大房间 
	MAX = max,dir='a';
	for (o = 1; o <= m; o++)
	{
		for (int i = (n - 1) * m + o; i > 0; i = i - m)
		{
			if (i > m)//北
			{
				if (find_root(i) != find_root(i - m)) {

					if (root[find_root(i)] + root[find_root(i - m)] > MAX)
					{
						MAX = root[find_root(i)] + root[find_root(i - m)];
						M = i;//M是该点的一维位置坐标
						dir = 'N';//dis记为方向
					}
				}
			}
			if (i % m != 0)//东
			{
				if (find_root(i) != find_root(i + 1)) {
					if (root[find_root(i)] + root[find_root(i + 1)] > MAX)
					{
						MAX = root[find_root(i)] + root[find_root(i + 1)];
						M = i;
						dir = 'E';
					}
				}
			}
		}
	}
	printf("%d\n", num);
	printf("%d\n", max);
	printf("%d\n", MAX);
	if (M % m == 0) {
		printf("%d  %d   %c", M / m, m, dir);
	}
	else {
		printf("%d  %d   %c", M / m + 1, M % m, dir);
	}
	return 0;
}
