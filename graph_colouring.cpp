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

const int N=5030;
int n,m,a,b,c,suc=1,odd,even,cnt=0;
VI g(N),ans(N,-1),gp(N,-1); //grouping, final answer, parity of group
vector<PII> p; //pairs of possibilities for each group
vector<VI> dp(N,VI(N,-1)),adj(N); // dp: number of group, possible values of even

void dfs(int u, int par){
    if (ans[u]!=-1){
        if (par != ans[u])suc=0;
        return;
    }
    ans[u]=par;
    g[u]=cnt;
    if (par)odd++;
    else even++;
    each(i,adj[u]){
        dfs(i,par^1);
    }
}

int main(){
    upgrade();
    cin>>n>>m>>a>>b>>c;
    rep(i,0,m){
        int l,r;cin>>l>>r;
        adj[l].pb(r);
        adj[r].pb(l);
    }
    rep(i,1,n+1){
        if (ans[i]==-1){
            odd=even=0;
            dfs(i,0);
            p.pb(mp(odd,even));
            cnt++;
        }
    }
    if (!suc){
        cout<<"NO"<<nl;return 0;
    }
    //DEBUG(1);
    dp[0][0]=1;
    rep(i,1,cnt+1){
        rep(j,0,N){
            if (dp[i-1][j]!=1)continue;
            dp[i][j+p[i-1].fi]=1;
            dp[i][j+p[i-1].se]=1;
        }
    }
    //DEBUG(1);
    suc=0;
    rep(j,0,N){
        if (dp[cnt][j]!=1)continue;
        if (b==j){
            suc=1;
            per(i,0,cnt){
                int f,s;
                f=b-p[i].fi,s=b-p[i].se;
                if (dp[i][f]==1){
                    gp[i]=1;
                    b=f;
                }
                else gp[i]=0,b=s;
            }
            //assert(b==0);
            break;
        }
    }
    if (!suc){
        cout<<"NO"<<nl;return 0;
    }
    cout<<"YES"<<nl;
    rep(i,1,n+1){
        int t=gp[g[i]]^ans[i];
        if (t==0)cout<<2;
        else if (a>0){
            cout<<1;
            a--;
        }
        else cout<<3;
    }
    cout<<nl;
}