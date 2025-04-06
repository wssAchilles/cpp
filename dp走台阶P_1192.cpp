#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[100005];
int ans(int n,int k){
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				dp[i]=(dp[i-j]+dp[i])%100003;
			}
		}
	}
	return dp[n];
}
int main(){
	scanf("%d%d",&n,&k);
	printf("%d",ans(n,k));
}