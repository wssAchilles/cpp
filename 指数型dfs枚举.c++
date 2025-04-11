#include<bits\stdc++.h>
using namespace std;
int n;
const int N=20;
int st[N];
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            if(st[i]==1){
                printf("%d ",i);
            }
        }
		printf("\n");
        return;
    }else{
        st[x]=2;
        dfs(x+1);
        
        st[x]=1;
        dfs(x+1);
        
        st[x]=0;
    }
}
int main(){
    scanf("%d",&n);
    dfs(1);
}