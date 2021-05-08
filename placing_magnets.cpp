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
const int N=1010;
int a[N][N];

int main(){
    upgrade();
    int n,m;cin>>n>>m;
    rep(i,0,n)rep(j,0,m){
        char c;cin>>c;
        if (c=='.')a[i][j]=0;
        else a[i][j]=1;
    }
    bool suc=true;
    int cnt=a[0][0]==1;
    rep(i,1,n){
        int j=0;
        if (a[i][j]==1&&a[i-1][j]==0){
            cnt++;
            if (cnt==2)suc=0;
        }
    }
    cnt=a[0][m-1]==1;
    rep(i,1,n){
        int j=m-1;
        if (a[i][j]==1&&a[i-1][j]==0){
            cnt++;
            if (cnt==2)suc=0;
        }
    }
    cnt=a[0][0]==1;
    rep(j,1,m){
        int i=0;
        if (a[i][j]==1&&a[i][j-1]==0){
            cnt++;
            if (cnt==2)suc=0;
        }
    }
    cnt=a[n-1][0]==1;
    rep(j,1,m){
        int i=n-1;
        if (a[i][j]==1&&a[i][j-1]==0){
            cnt++;
            if (cnt==2)suc=0;
        }
    }
    if (!suc){
        cout<<-1<<nl;
        return 0;
    }
    if(n==1 || m==1){
        cout<<1<<nl;
        return 0;
    }
    int ans=1;
    if (a[0][0]==1&&a[1][0]==0&&a[0][1]==0)ans++;
    if (a[n-1][0]==1&&a[n-2][0]==0&&a[n-1][1]==0)ans++;
    if (a[0][m-1]==1&&a[1][m-1]==0&&a[0][m-2]==0)ans++;
    if (a[n-1][m-1]==1&&a[n-2][m-1]==0&&a[n-1][m-2]==0)ans++;
    cout<<ans<<nl;
}