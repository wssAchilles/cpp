#include<bits/stdc++.h>
using namespace std;
int m,n,sx,sy,fx,fy;
int arry[100][100], vis[100][100];
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // 左上右下的优先顺序
struct node{
	int x;
	int y;
	int step;
};
queue<node> r;
int dfs(int x,int y){
	node start;
	start.x=x,start.y=y,start.step=0;
	r.push(start); // 将起点入队
	vis[x][y]=1;
	while(!r.empty()){
		int x=r.front().x,y=r.front().y;
		if(x==fx&&y==fy){
			return r.front().step;
		}
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx >= 1 && nx <= m && ny >= 1 && ny <= n && vis[nx][ny]==0&&arry[nx][ny]==1){
				node temp;
				temp.x=nx,temp.y=ny,temp.step=r.front().step+1;
				r.push(temp);
				vis[nx][ny]=1;
			}
		}
		r.pop();
	}
}