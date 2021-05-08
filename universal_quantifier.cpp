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

int n,m,suc=1,cnt1=0,cnt2=0;
VI adj[N]; //adj[i] is list of vectors that i can connect to 
vector<bool> done(N,0),s(N,0),e(N,0),vis(N,0);

void dfs(int u){
    if (done[u]==1){
        suc=0;return;
    }
    if (vis[u]==1)return;
    vis[u]=1;
    done[u]=1;
    each(i,adj[u]){
        if (s[u]==1 && i==u+1)e[i]=1;
        s[i]=0;
        dfs(i);
    }/*
    if (SZ(adj[u])==0){
        e[u]=1;cnt2++;
    }*/
    done[u]=0;
}

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
    }
    rep(i,1,n+1){
        if (vis[i]==1)continue;
        dfs(i);
        cnt1++;
        s[i]=1;
    }
    if (!suc){
        cout<<-1<<nl;return 0;
    }/*
    if (cnt2>cnt1){
        swap(cnt1,cnt2);
        swap(e,s);
    }*/
    cout<<cnt1<<nl;
    rep(i,1,n+1){
        if (s[i])cout<<'A';
        else {
            cout<<'E';
            //d=0;
        }
    }
    cout<<nl;
}