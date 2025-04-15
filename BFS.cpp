#include <bits/stdc++.h>
using namespace std;
int a[100][100], vis[100][100];
int ex, ey, fx, fy, m, n;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
struct point
{
	int x;
	int y;
	int step;
};
queue<point> r;
int main()
{
	// 输入
	int n, m, startx, starty, p, q;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	scanf("%d%d%d%d", &startx, &starty, &p, &q);
	// BFS
	r.push(point{startx,starty,0}); // 将起点入队
	vis[startx][starty] = 1;
	int flag = 0;
	while (!r.empty())
	{
		int x = r.front().x, y = r.front().y;
		if (x == p && y == q)
		{
			flag = 1;
			printf("%d", r.front().step);
			break;
		}
		for (int k = 0; k <= 3; k++)
		{
			int tx, ty;
			tx = x + dx[k];
			ty = y + dy[k];
			if (a[tx][ty] == 1 && vis[tx][ty] == 0)
			{
				// 入队
				point temp;
				temp.x = tx;
				temp.y = ty;
				temp.step = r.front().step + 1;
				r.push(temp);
				vis[tx][ty] = 1;
			}
		}
		r.pop(); // 出队
	}
	if (flag == 0)
		printf("no answer!");
	return 0;
}