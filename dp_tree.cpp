#include <vector>
#include <stdio.h>

using namespace std;

int dp[1000000][2];
int weight[1000000];
vector<int> adj[1000000];

int solve(int i, int parent){
    for (int child:adj[i]){
        if (child == parent) continue;
        solve(child,i), solve(child,i);
        dp[i][1] += dp[child][0];
        dp[i][0] += max(dp[child][1], dp[child][0]);
    }
    dp[i][1] += weight[i];
}

int main(){
    int n=1234;
    solve(1,-1), solve(1,-1);
    printf("%d\n", max(dp[1][0], dp[1][1]));
}