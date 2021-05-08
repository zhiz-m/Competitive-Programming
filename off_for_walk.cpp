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
int n,m;
vector<PII> adj[N];
map<PII,int> s;
ll ans=0,cnt=0;

void dfs(int u, int prev, ll tot, bitset<510> bits){
    if (u==1 && prev!=-1)return;
    if (tot>2000)return;
    if (u!=1 || prev!=-1){
        if (s.count(mp(1,u))){
            ll t=tot+s[mp(1,u)];
            if (t<=2000){
                cnt++;
                ans+=t;
            }
        }
    }
    each(i,adj[u]){
        if (i.fi==prev || bits[i.fi])continue;
        bits[i.fi]=1;
        dfs(i.fi,u,tot+i.se,bits);
        bits[i.fi]=0;
    }
}

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,0,m){
        int a,b,c;cin>>a>>b>>c;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
        if (a==1 || b==1){
            if (a==1) swap (a,b);
            s[mp(b,a)]=c;
        }
    }
    dfs(1,-1,0,bitset<510>());
    if (cnt==0){
        cout<< "Stuck inside!"<<nl;
    }
    else{
        cout<<cnt<<' '<<ans<<nl;
    }
}