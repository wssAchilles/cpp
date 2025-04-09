#include<bits/stdc++.h>
using namespace std;
int n;
int ans=1e9;//存答案
const int N=10;
int arry[N+1];//存方案
int acid[N+1],bitter[N+1];
int st[N+1];//存放与不放的状态(1选 2不选 0清空)
void dfs(int x){
	if(x>n){
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(st[i]==1){
				flag=1;
				break;
			}
		}
		if(!flag) return;//如果没有选任何东西，直接返回
		int sum1=1,sum2=0;
		for(int i=1;i<=n;i++){
			if(st[i]==1) {
				sum1*=acid[i];
				sum2+=bitter[i];
			}
		}
		ans=min(ans,abs(sum1-sum2));
		return;
	}
	else{
		st[x]=1;//选
		dfs(x+1);
	
		st[x]=2;//不选
		dfs(x+1);

		st[x]=0;//清空状态	
		// 这里的清空状态是为了防止下次dfs时，状态不清空，导致错误的结果
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&acid[i],&bitter[i]);
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}