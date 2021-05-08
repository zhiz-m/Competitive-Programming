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

const int N=500500;

vector<VI> adj(N);
vector<PII> v(N); //colour, blog number
VI done(N);
int n,m;

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b),adj[b].pb(a);
    }
    rep(i,1,n+1){
        cin>>v[i].fi;
        v[i].se=i;
    }
    bool suc=1;
    rep(i,1,n+1){
        int c=v[i].fi;
        if (SZ(adj[i])<c-1){
            suc=0;break;
        }
        rep(j,1,c){
            done[j]=0;
        }
        each(u,adj[i]){
            if (v[u].fi==c)suc=0;
            else done[v[u].fi]=1;
        }
        rep(j,1,c){
            if (done[j]!=1)suc=0;
        }
    }
    if (!suc){
        cout<<-1<<nl;
    }
    else{
        sort(v.begin()+1,v.begin()+n+1);
        rep(i,1,n+1)cout<<v[i].se<<' ';
        cout<<nl;
    }
}