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

const int N=32;
vector<VI> grid(N,VI(N));
int n,m,ans;

void solve(){
    cin>>n>>m;
    rep(i,0,n){
        rep(j,0,m)cin>>grid[i][j];
    }
    int l=0,r=n+m-2;
    ans=0;
    for(;l<r;l++,r--){
        //DEBUG(l),DEBUG(r);
        int a,b;a=b=0;
        int x=l,y=0;
        for(;x>=0&&y<n;x--,y++){
            if (x>=m)continue;
            //cout<<grid[x][y]<<' ';
            if (grid[y][x]==1)a++;
            else b++;
        }
        //cout<<nl;
        x=r,y=0;
        for(;x>=0&&y<n;x--,y++){
            if (x>=m)continue;
            //cout<<grid[y][x]<<' ';
            if (grid[y][x]==1)a++;
            else b++;
        }
        //cout<<nl;
        //DEBUG(a),DEBUG(b);
        ans+=min(a,b);
    }
    cout<<ans<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
}