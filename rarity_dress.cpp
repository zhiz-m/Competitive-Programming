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

const int N=2020;
int n,m;
char grid[N][N];
bool dp[N][N][10], done[N][N];

int check(int x, int y, int dist, int num){
    int nx[] = {x-dist, x+dist, x, x};
    int ny[] = {y,y,y-dist, y+dist};
    rep(i,0,4){
        if (nx[i]<0 || nx[i]>=n || ny[i]<0 || ny[i]>=m) return 0;
        if (grid[nx[i]][ny[i]]!=grid[x][y] || dp[nx[i]][ny[i]][num]==0) return 0;
    }
    return 1;
}

int iter(int x, int y, int num){
    if (num==0){
        if (x==0 || y==0 || x==n-1 || y==m-1) return 0;
        if (grid[x-1][y]==grid[x][y] && grid[x+1][y]==grid[x][y] && grid[x][y-1]==grid[x][y] && grid[x][y+1]==grid[x][y])return 1;
        return 0;
    }
    return check(x,y,1<<(num-1),num-1);
}

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,0,n){
        string s;cin>>s;
        rep(j,0,m)grid[i][j]=s[j],done[i][j]=1;
    }
    rep(num,0,10)rep(i,0,n)rep(j,0,m){
        if (done[i][j]==0)continue;
        dp[i][j][num] = done[i][j] = iter(i,j,num);
    }
    ll ans=0;
    rep(i,0,n)rep(j,0,m){
        int x=-1;
        per(num,0,10) if (dp[i][j][num]==1){
            x=num;
            break;
        }
        if (x==-1){
            ans+=1;
            continue;
        }
        int l=0,r=(1<<x)+1;
        while(l+1!=r){
            int mid=(l+r)/2;
            if (check(i,j,mid,x))l=mid;
            else r=mid;
        }
        ans+=l+(1<<x)+1;
    }
    cout<<ans<<nl;
}