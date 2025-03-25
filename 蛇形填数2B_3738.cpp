#include<bits/stdc++.h>
using namespace std;
int isPrime(int n){
	if(n==1) return 0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int main(){
	int n,l,r;
	cin>>n>>l>>r;
	int prime[n*n],a[n][n];
	memset(a,0,sizeof(a));
	int num=0;
	for(int i=2;num<n*n;i++){
		if(isPrime(i)){
			prime[num++]=i;
		}
	}
	int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
	int dir=0,x=0,y=0;
	int nx=x+dx[dir],ny=y+dy[dir];
	for(int i=0;i<n*n;i++){
		a[x][y]=prime[i];
		if(nx<0||nx>=n||ny<0||ny>=n||a[nx][ny]!=0){
			dir=(dir+1)%4;
			nx=x+dx[dir];
			ny=y+dy[dir];
		}
		x=nx;
		y=ny;
		nx=x+dx[dir];
		ny=y+dy[dir];
	}
	cout << a[l-1][r-1] << endl;
    return 0;
}
