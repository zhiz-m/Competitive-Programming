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

const int N=220;
int n[3],v[3][N],dp[N][N][N];

int recur(int a, int b, int c){
    if (dp[a][b][c]!=-1)return dp[a][b][c];
    int t[] = {a,b,c},ch[3];
    int ans=0;
    rep(i,0,3)rep(j,i,3){
        if (i==j)continue;
        if (t[i]==0 || t[j]==0)continue;
        ch[0]=ch[1]=ch[2]=0;
        ch[i]=ch[j]=1;
        ans=max(ans,v[i][t[i]]*v[j][t[j]]+recur(t[0]-ch[0],t[1]-ch[1],t[2]-ch[2]));
    }
    return dp[a][b][c]=ans;
}

int main(){
    upgrade();
    memset(dp,-1,sizeof(dp));
    cin>>n[0]>>n[1]>>n[2];
    rep(i,0,3){
        rep(j,1,n[i]+1)cin>>v[i][j];
        sort(v[i]+1,v[i]+n[i]+1);
    }
    cout<<recur(n[0],n[1],n[2])<<nl;
}