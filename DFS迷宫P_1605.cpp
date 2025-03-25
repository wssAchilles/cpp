#include<bits/stdc++.h>
using namespace std;
int arry[10][10];
bool vis[10][10];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int N,M,T,sx,sy,fx,fy,x,y,ans=0;
void dfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return;
	}
	else{
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>0&&nx<=N&&ny>0&&ny<=M&&!vis[nx][ny]&&arry[nx][ny]==0){
				vis[x][y]=1;
				dfs(nx,ny);
				vis[x][y]=0;
			}
		}
	}
}
int main(){
	cin>>N>>M>>T;
	cin>>sx>>sy>>fx>>fy;
	memset(arry,0,sizeof(arry));
	for(int i=1;i<=T;i++){
		cin>>x>>y;
		arry[x][y]=1;
	}
	dfs(sx,sy);
	cout<<ans;
}