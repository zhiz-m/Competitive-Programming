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

const int N=1010;
int n,m,k,t;
vector<VI> v(N,VI(N)),ans(N,VI(N,-1)),d(N,VI(N,0));

void dfs1(int x,int y){
    if (x>=n || y>=m || x<0 || y<0 || ans[x][y]==0)return;
    if (v[x][y]==1){
        t+=1;return;
    }
    ans[x][y]=0;
    dfs1(x-1,y);
    dfs1(x+1,y);
    dfs1(x,y+1);
    dfs1(x,y-1);
}

void dfs2(int x, int y){
    if (x>=n || y>=m || x<0 || y<0 ||v[x][y]==1|| d[x][y])return;
    ans[x][y]=t;
    d[x][y]=1;
    dfs2(x-1,y);
    dfs2(x+1,y);
    dfs2(x,y+1);
    dfs2(x,y-1);
}

int main(){
    upgrade();
    cin>>n>>m>>k;
    rep(i,0,n){
        string s;cin>>s;
        rep(j,0,m){
            if (s[j]=='.')v[i][j]=0;//empty
            else v[i][j]=1;//not empty
        }
    }
    rep(i,0,n)rep(j,0,m){
        if (ans[i][j]==-1 && v[i][j]==0){
            t=0;
            dfs1(i,j);
            dfs2(i,j);
        }
    }
    rep(i,0,k){
        int x,y;cin>>x>>y;
        cout<<ans[x-1][y-1]<<nl;
    }
}