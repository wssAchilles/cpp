#include<bits/stdc++.h>
using namespace std;
int m,n,ex,ey,fx,fy,k=0,flag=0,ans=0;
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int vis[10][10],arry[10][10],sum[5000][2],step[1000];
void print(){
	if(flag==0){
		flag=1;
	}
	
	for(int i=0;i<k;i++){
		cout<<"("<<sum[i][0]<<","<<sum[i][1]<<")"<<"->";
	}
	cout<<"("<<fx<<","<<fy<<")"<<"总共"<<k<<"步"<<endl;
}
void dfs(int x,int y){
	if(x==fx&&y==fy){
		print();
		step[ans++]=k;
		return;
	}
	else{
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>0&&nx<=m&&ny>0&&ny<=n&&vis[nx][ny]==0&&arry[nx][ny]==1){
				vis[x][y]=1;
				sum[k][0]=x;sum[k][1]=y;
				k++;
				dfs(nx,ny);
				vis[x][y]=0;
				k--;
			}
		}
	}
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>arry[i][j];
		}
	}
	cin>>ex>>ey;
	cin>>fx>>fy;
	dfs(ex,ey);
	int *min=min_element(step,step+ans);
	printf("最少%d步",*min);
	if(flag==0){
		cout<<"-1";
	}
	return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int m,n,ex,ey,fx,fy,k=0,flag=0;
// int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0}; // 左上右下的优先顺序
// int vis[16][16],arry[16][16],sum[5000][2];

// void print(){
//     if(flag==0){
//         flag=1;
//     }
//     for(int i=0;i<k;i++){
//         cout<<"("<<sum[i][0]<<","<<sum[i][1]<<")"<<"->";
//     }
//     cout<<"("<<fx<<","<<fy<<")"<<endl;
// }

// void dfs(int x,int y){
//     // 将当前点存入路径
//     sum[k][0]=x;sum[k][1]=y;
//     k++;
    
//     if(x==fx&&y==fy){
//         // 在print函数里已经单独输出终点，所以这里k减1，不要重复
//         k--;
//         print();
//         k++;  // 恢复k值用于回溯
//     }
//     else{
//         for(int i=0;i<4;i++){
//             int nx=x+dx[i],ny=y+dy[i];
//             // 使用1-based索引的边界检查
//             if(nx>=1 && nx<=m && ny>=1 && ny<=n && vis[nx][ny]==0 && arry[nx][ny]==1){
//                 vis[nx][ny]=1; // 标记新位置为已访问
//                 dfs(nx,ny);
//                 vis[nx][ny]=0; // 回溯时取消标记
//             }
//         }
//     }
    
//     // 回溯，从路径中移除当前点
//     k--;
// }

// int main(){
//     cin>>m>>n;
    
//     // 使用1-based索引读取迷宫数据
//     for(int i=1;i<=m;i++){
//         for(int j=1;j<=n;j++){
//             cin>>arry[i][j];
//         }
//     }
    
//     cin>>ex>>ey;
//     cin>>fx>>fy;
    
//     // 检查终点是否在有效范围内并可达
//     if(fx < 1 || fx > m || fy < 1 || fy > n || arry[fx][fy] == 0) {
//         cout << "-1" << endl;
//         return 0;
//     }
    
//     // 检查起点是否在有效范围内并可达
//     if(ex < 1 || ex > m || ey < 1 || ey > n || arry[ex][ey] == 0) {
//         cout << "-1" << endl;
//         return 0;
//     }
    
//     // 初始化访问数组
//     memset(vis, 0, sizeof(vis));
//     vis[ex][ey]=1; // 标记起点为已访问
    
//     dfs(ex,ey);
    
//     if(flag==0){
//         cout<<"-1";
//     }
    
//     return 0;
// }