//您当前的程序使用DFS（深度优先搜索）方法查找最短路径，
//但存在一个严重问题：没有机制避免循环。没有visited数组，
//搜索可能会无限重复访问相同的位置，导致无限递归和栈溢出。
//寻找最短路径最推荐的方式是使用BFS（广度优先搜索），
//它可以有效地找到最短路径而不会陷入循环。
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,A,B;
int evlt[N];
int res=1e9;
bool visited[N];
void dfs(int x,int cnt){
	if(x==B){
		res=min(res,cnt);
		return;
	}
	if(x+evlt[x]<=n&&!visited[x+evlt[x]]){
		visited[x+evlt[x]]=1;
		dfs(x+evlt[x],cnt+1);
		visited[x+evlt[x]]=0;
	}
	if(x-evlt[x]>=1&&!visited[x-evlt[x]]){
		visited[x-evlt[x]]=1;
		dfs(x-evlt[x],cnt+1);
		visited[x-evlt[x]]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;i++){
		scanf("%d",&evlt[i]);
	}
	memset(visited, false, sizeof(visited)); // 初始化访问数组
    visited[A] = true; // 标记起点为已访问
	dfs(A,0);
	if(res==1e9){
		printf("-1\n");
	}else{
		printf("%d\n",res);
	}
}