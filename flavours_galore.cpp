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
typedef long double ld;
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N=100100;
int f,p, vis[N], cur[N], suc=0;
VI adj[N], path;
/*
void dfs2(int u){
    if (suc)return;
    if (vis[u]){
        suc=1;
        DEBUG(u);
        return;
    }
    vis[u]=1;
    each(i,adj[u]){
        dfs2(i);
    }
}*/

void dfs(int u){
    if (cur[u]!=0 || suc)return;
    if (vis[u]){
        suc=1;
        return;
    }
    path.pb(u);
    vis[u]=1;
    each(i,adj[u]){
        dfs(i);
        cur[u]=max(cur[u],cur[i]);
    }
    cur[u]++;
}

int main(){
    upgrade();
    cin>>f>>p;
    rep(i,1,f+1)vis[i]=0, cur[i]=0;
    rep(i,0,p){
        int a,b;cin>>a>>b;
        adj[b].pb(a);
    }/*
    rep(i,1,f+1)if (!vis[i])dfs2(i);
    if (suc){
        cout<<-1<<nl;
        return 0;
    }*/
    rep(i,1,f+1){
        path.clear();
        dfs(i);
        each(j,path) vis[j]=0;
    }
    if (suc){
        cout<<-1<<nl;
        return 0;
    }
    int mx=-1;
    rep(i,1,f+1){
        mx=max(cur[i],mx);
    }
    cout<<mx<<nl;
}