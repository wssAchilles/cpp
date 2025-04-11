#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,sx,sy,fx,fy;
int arry[N][N],vis[N][N];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct node{
	int x,y,step;
};
queue<node> r;
int bfs(int x,int y){
	memset(vis,0,sizeof(vis));
	node start;
	start.x=x,start.y=y,start.step=0;
	r.push(start);
	vis[x][y]=1;
	while(!r.empty()){
		int x=r.front().x,y=r.front().y;
		if(x==fx&&y==fy){
			return r.front().step;
		}
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n &&vis[nx][ny]==0&&arry[nx][ny]==0){
				node temp;
				temp.x=nx,temp.y=ny,temp.step=r.front().step+1;
				r.push(temp);
				vis[nx][ny]=1;
			}
		}
		r.pop();
	}
	return -1; // 如果没有路径返回-1
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&arry[i][j]);
		}
	}
	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
	int ans=bfs(sx,sy);
	printf("%d",ans);
	return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1005;
// int n, sx, sy, fx, fy,k=0,ans=0;
// int arry[N][N], vis[N][N],step[N];
// int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
// void dfs(int x,int y){
// 	memset(vis,0,sizeof(vis));
// 	if(x==fx&&y==fy){
// 		step[ans++]=k+1;
// 		return;
// 	}else{
// 		for(int i=0;i<4;i++){
// 			int nx=x+dx[i],ny=y+dy[i];
// 			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && vis[nx][ny]==0&&arry[nx][ny]==0){
// 				vis[x][y]=1;
// 				k++;
// 				dfs(nx,ny);
// 				vis[x][y]=0;
// 				k--;
// 			}
// 		}
// 	}
// }
// int main(){
// 	scanf("%d",&n);
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=n;j++){
// 			scanf("%d",&arry[i][j]);
// 		}
// 	}
// 	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
// 	dfs(sx,sy);
// 	int *min=min_element(step,step+ans);
// 	printf("%d",*min);
// }