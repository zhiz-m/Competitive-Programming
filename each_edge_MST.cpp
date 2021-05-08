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
int n,m,lca[N][20],dsu[N],s[N],l[N];
ll tot,mx[N][20];
VI adj[N]={};
PII e[N];
tuple<ll, int, int> v[N];
map<PII,ll> w;

int head(int a){
    if (dsu[a]==a)return a;
    return dsu[a]=head(dsu[a]);
}

void dfs(int u, int prev, int d){
    lca[u][0]=prev;
    l[u]=d++;
    if (prev!=-1)mx[u][0]=w[mp(u,prev)];
    if (u!=1)
    rep(i,1,20){
        lca[u][i]=lca[lca[u][i-1]][i-1];
        if (lca[u][i]==-1)break;
        mx[u][i]=max(mx[u][i-1],mx[lca[u][i-1]][i-1]);
    }
    //DEBUG(9);
    each(i,adj[u]){
        if (i==prev)continue;
        dfs(i,u,d);
    }
}

ll get(int a, int b){
    ll ret=-1;
    if (l[a]>l[b])swap(a,b);
    per(i,0,20){
        if (lca[b][i]==-1||l[lca[b][i]]<l[a])continue;
        ret=max(ret,mx[b][i]);
        b=lca[b][i];
    }
    if (a==b)return ret;
    per(i,0,20){
        if (lca[a][i]==-1||lca[b][i]==-1||lca[a][i]==lca[b][i])continue;
        ret=max(ret,mx[b][i]);
        ret=max(ret,mx[a][i]);
        a=lca[a][i],b=lca[b][i];
    }
    //DEBUG(a);
    return max(mx[b][0],max(ret,mx[a][0]));
}

int main(){
    upgrade();
    cin>>n>>m;
    tot=0;
    rep(i,1,n+1)rep(j,0,20)lca[i][j]=mx[i][j]=-1;
    rep(i,0,m){
        int a,b,c;cin>>a>>b>>c;
        e[i]=mp(a,b);
        w[mp(a,b)]=w[mp(b,a)]=c;
        v[i]=make_tuple(c,a,b);
    }
    sort(v,v+m);
    rep(i,1,n+1)dsu[i]=i,s[i]=1;
    rep(i,0,m){
        int a,b;a=get<1>(v[i]),b=get<2>(v[i]);
        int x=head(a);
        int r=head(b);
        if (x==r)continue;
        tot+=get<0>(v[i]);
        if (s[x]<s[r])swap(a,b),swap(x,r);
        s[x]+=s[r];
        adj[a].pb(b),adj[b].pb(a);
        dsu[r]=x;
    }
    //rep(i,1,n+1)DEBUG(s[head(i)]);
    dfs(1,-1,1);
    //DEBUG(tot);
    rep(i,0,m){
        cout<<tot-get(e[i].fi,e[i].se)+w[mp(e[i].fi,e[i].se)]<<nl;
    }
}