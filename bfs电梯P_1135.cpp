#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int main(){
    int n, A, B;
    int evlt[N];
    bool visited[N] = {false};
    
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1;i<=n;i++){
        scanf("%d",&evlt[i]);
    }
    
    queue<pair<int, int>> q;  // (位置, 步数)
    q.push({A, 0});
    visited[A] = true;
    
    while(!q.empty()){
        auto [pos, steps] = q.front();
        q.pop();
        
        if(pos == B){
            printf("%d\n", steps);
            return 0;
        }
        
        int forward = pos + evlt[pos];
        int backward = pos - evlt[pos];
        
        if(forward <= n && !visited[forward]){
            visited[forward] = true;
            q.push({forward, steps + 1});
        }
        
        if(backward >= 1 && !visited[backward]){
            visited[backward] = true;
            q.push({backward, steps + 1});
        }
    }
    
    printf("-1\n");  // 未找到路径
    return 0;
}