#include<bits/stdc++.h>
using namespace std;
int fire[11]={6,2,5,5,4,5,6,3,7,6};
int s(int x){
	if(x==0) return fire[0];
	int ans=0;
	while(x!=0){
		ans+=fire[x%10];
		x/=10;
	}
	return ans;
}
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			if(s(i)+s(j)+s(i+j)==n-4){
				ans++;
				printf("%d %d %d\t\n",i,j,i+j);
			}
		}
	}
	printf("%d",ans);
	return 0;
}