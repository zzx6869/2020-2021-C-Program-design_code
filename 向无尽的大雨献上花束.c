//2021.1.7
//zzx  并查集版本——————


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int pre[100000]; 					   //存储每个结点的前驱结点 
int rank[100000];                      //树的高度 
_Bool mark[100000];                     //储存两个城市（节点）之间是否连通

void init(int n)     					//初始化函数，对录入的n个结点进行初始化 
{
    for (int i = 0; i < n; i++) {
        pre[i] = i;     				//每个结点的上级都是自己 
        rank[i] = 1;    				//每个结点构成的树的高度为1 
    }
}

/*
int find_pre(int x)     	 		    //查找结点x的根结点 
{
    if (pre[x] == x) return x;  			//递归出口：x的上级为x本身，则x为根结点 
    return find_pre(pre[x]); 			//递归查找 
}
//合并：
void join(int x,int y)                    //试图合并元素x和元素y
{
    int fx=find(x), fy=find(y); 		  //找到x和y的源头
    if(fx != fy) pre[fx]=fy;  			  //合并两个源头
}

*/

//改进查找算法：完成路径压缩，将x的上级直接变为根结点，那么树的高度就会大大降低 

int find_pre(int x)     				//查找结点x的根结点 
{
    if (pre[x] == x) return x;			//递归出口：x的上级为x本身，即x为根结点 
    return pre[x] = find_pre(pre[x]);   //此代码相当于先找到根结点rootx，然后pre[x]=rootx 
}


_Bool is_same(int x, int y)      		//判断两个结点是否连通 
{
    return find_pre(x) == find_pre(y);  //判断两个结点的根结点（亦称代表元）是否相同 
}


_Bool unite(int x, int y)
{
    x = find_pre(x);
    y = find_pre(y);
    if (x == y) 
        return 0;
    if (rank[x] > rank[y]) pre[y] = x;		//令y的根结点的上级为x
    else
    {
        if (rank[x] == rank[y])  rank[y]++;
        pre[x] = y;
    }
    return 1;
}

//主函数:
int main()
{
    int M, N, a, b, f = -1, e = -1, t, k = 0;
	scanf("%d%d", &N, &M);
    init(N);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &a,&b);
        unite(a-1, b-1);
    }
    while ((f != 0) && (e != 0))
    {
        scanf("%d%d", &e, &f);
        if ((f == 0) && (e == 0))
            break;
        mark[k] = is_same(e-1, f-1);
        k++;
    }
    for (int i = 0; i < k;i++) 
    {
        if (mark[i] == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
