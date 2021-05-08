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

const int N=300300;
vector<VI> adj(N);
VI od(N),path,done(N,0),col(N);
int n,m,k,suc=0;

void dfs2(int u, int prev, int c){
    if (col[u]!=-1){
        col[u]=c;
        return;
    }
    col[u]=c;
    each(i,adj[u]){
        if (i==prev)continue;
        dfs2(i,u,c^1);
    }
}

void dfs(int u, int prev, int cnt){
    if (suc)return;
    if (done[u]){
        int t=cnt-od[u];
        if (t<=1)return;
        if (t<=k){
            suc=1;
            cout<<2<<nl<<t<<nl;
            cout<<u<<' ';
            while(path.back()!=u){
                cout<<path.back()<<' ';
                path.pop_back();
            }
            cout<<nl;
        }
        else{
            suc=1;
            int cnt=k-k/2;
            cout<<1<<nl;
            while(cnt!=0){
                cout<<path.back()<<' ';
                cnt--;
                path.pop_back();
                path.pop_back();
            }
            cout<<nl;
        }
        return;
    }
    path.pb(u);
    od[u]=cnt;
    done[u]=1;
    each(i,adj[u]){
        if (i==prev)continue;
        dfs(i,u,cnt+1);
    }
    path.pop_back();
}

int main(){
    upgrade();
    cin>>n>>m>>k;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    rep(i,1,n+1){
        if (done[i])continue;
        od[i]=0;
        dfs(i,-1,0);
        if (suc)return 0;
    }
    rep(i,1,n+1)col[i]=-1;
    rep(i,1,n+1){
        if (col[i]!=-1)continue;
        dfs2(i,-1,1);
    }
    int d=0;
    cout<<1<<nl;
    rep(i,1,n+1){
        if (col[i]==1)cout<<i<<' ',d++;
        if (d==k-k/2)break;
    }
    cout<<nl;
    return 0;
}