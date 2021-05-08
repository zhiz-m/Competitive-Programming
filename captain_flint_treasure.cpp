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

const int N=200200;
ll a[N],b[N],num[N],cnt,n,done[N];
VI adj[N],ans;
queue<pair<int,int>> q;

void dfs(int u, int prev, int x){
    done[u]=1;
    if (x==2 && a[u]>=0)return;
    if (a[u]>0 || x==2)cnt+=a[u],ans.pb(u);
    if (x==0 && a[u]<0)x++;
    if (x==1 && a[u]>=0){
        q.push(mp(prev,u));
        DEBUG(prev);
        x=0;
    }
    int suc=0;
    each(i,adj[u]){
        if (done[i]==1)continue;
        //if (u==6)DEBUG("hi");
        num[i]--;
        if (a[u]>0)a[i]+=a[u];
        if (num[i]<=0){
            dfs(i,u,x);
        }
        suc=1;
    }
    if (x==1 && suc==0 && a[u]<0){
        q.push(mp(u,-1));
    }
}

void dfs2(int u, int prev){
    assert(a[u]<0);
    cnt+=a[u],ans.pb(u);
    each(i,adj[u]){
        if (i==prev || a[i]>=0)continue;
        dfs2(i,u);
    }
}

int main(){
    upgrade();
    cin>>n;
    rep(i,1,n+1)cin>>a[i],num[i]=0,done[i]=0;
    rep(i,1,n+1){
        cin>>b[i];
        if (b[i]==-1)continue;
        num[b[i]]++,adj[b[i]].pb(i),adj[i].pb(b[i]);
    }
    rep(i,1,n+1){
        if (num[i]==0 && done[i]==0)dfs(i,-1,0);
    }
    while(!q.empty()){
        dfs2(q.front().fi,q.front().se);
        q.pop();
    }
    cout<<cnt<<nl;
    each(i,ans){
        cout<<i<<' ';
    }
    cout<<nl;
}