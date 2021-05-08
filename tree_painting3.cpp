#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,b) for (int i=a;i<b;i++)
#define each(a,x) for(auto&a:(x))
typedef long long ll;

const int N=200200;
int n;
ll dp[N][2], ans[N];
vector<int> adj[N];

// dp[i][0] is the number of vertices in subtree of i
// dp[i][1] is the total score earned when choosing every point in the subtree of i

void precalc(int u, int prev){
    dp[u][0] = 1, dp[u][1] = 0;
    each(child, adj[u]){
        if (child == prev) continue;
        precalc(child, u);
        dp[u][0] += dp[child][0];
        dp[u][1] += dp[child][1];
    }
    dp[u][1] += dp[u][0];
}

void reroot(int u, int prev){
    
    // remove total from previous root 
    dp[prev][1] -= dp[u][0] + dp[u][1];
    dp[prev][0] -= dp[u][0];
    dp[u][1] += dp[prev][1] + dp[prev][0];
    dp[u][0] += dp[prev][0];
    ans[u] = dp[u][1];
    each(child, adj[u]){
        if (child == prev) continue;
        reroot(child,u);
    }
    dp[u][0] -= dp[prev][0];
    dp[u][1] -= dp[prev][1] + dp[prev][0];
    dp[prev][0] += dp[u][0];
    dp[prev][1] += dp[u][0] + dp[u][1];
}

int main(){
    scanf("%d", &n);
    rep(i,1,n){
        int a,b;scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    precalc(1,-1);
    ans[1]=dp[1][1];
    each(child,adj[1]) reroot(child,1);
    ll mx = dp[1][1];
    rep(i,1,n+1)mx=max(mx, ans[i]);
    printf("%lld\n", mx);
}