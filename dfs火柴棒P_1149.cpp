#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int arry[4];
int ans=0,n;
int fire[N]={6,2,5,5,4,5,6,3,7,6};
void dfs(int x,int sum){
	if(sum>n){
		return;
	}
	if(x>3){
		if(arry[1]+arry[2]==arry[3]&&sum==n){
			ans++;
		} 
		return;
	}
	for(int i=0;i<=1000;i++){
		arry[x]=i;
		dfs(x+1,sum+fire[i]);
		arry[x]=0;
	}
}
int main(){
	scanf("%d",&n);
	n-=4;
	for(int i=10;i<=1000;i++){
		fire[i]=fire[i/10]+fire[i%10];
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}