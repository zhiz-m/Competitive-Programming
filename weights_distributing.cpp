#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define SZ(x) (int)(x).size()
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=b-1;i>=a;i--)
#define each(a,x) for(auto&a:(x))
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n'
#define nl '\n'
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef long long ll;
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO
const int N=200100;
VLL cost(N);
VI p(3);
vector<VI> adj,dist(3);
queue<PII> qu;
int n,m;

void bfs(int a, int d, int ind){
    if (dist[ind][a]>d){
        dist[ind][a]=d++;
        each(i,adj[a]){
            qu.emplace(i,d);
        }
    }
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        cin>>n>>m>>p[0]>>p[1]>>p[2];
        adj.assign(n+1,VI());
        //vis.assign(n+1,0);
        each(i,dist)i.assign(n+1,INT_MAX);
        rep(i,1,m+1)cin>>cost[i];
        sort(cost.begin(),cost.begin()+m+1);
        rep(i,1,m+1)cost[i]+=cost[i-1];
        rep(i,0,m){
            int a,b;cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        rep(ind,0,3){
            qu.emplace(p[ind],0);
            while(!qu.empty()){
                bfs(qu.front().fi,qu.front().se,ind);
                qu.pop();
            }
            //rep(i,1,n+1)cout<<dist[ind][i]<<' '; 
            //cout<<nl;
        }
        ll ans=LLONG_MAX;
        rep(i,1,n+1){
            int t=dist[0][i]+dist[1][i]+dist[2][i];
            if (t>m)continue;
            //DEBUG(t);
            ans=min(ans,cost[dist[1][i]]+cost[t]);
        }
        cout<<ans<<nl;
    }
}