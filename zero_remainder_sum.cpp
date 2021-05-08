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

const int N=75;
int n,m,k,v[N][N],dp[N][N][N][N],vis[N][N][N],cur; //n index, m index, number of values used, mod table
int temp1[N], temp2[N];

int recur(int u, int prev){
    //DEBUG(prev);
    if (prev==0){
        dp[cur][u][prev][0]=0;
        rep(i,1,k)dp[cur][u][prev][i]=-1;
        return 1;
    }
    if (u<=0) return -1;
    if (vis[cur][u][prev]) return 1;
    vis[cur][u][prev]=1;
    int suc1= recur(u-1, prev);
    int suc2=recur(u-1, prev-1);
    if (suc1!=-1){
        memset(temp1,-1,sizeof(temp1));
        rep(i,0,k)if(dp[cur][u-1][prev][i]!=-1) temp1[i]=dp[cur][u-1][prev][i];
        //if (cur==1 && u==5 && prev==2) rep(i,0,k) DEBUG(temp1[i]);
    }
    if (suc2!=-1){
        memset(temp2,-1,sizeof(temp2));
        rep(i,0,k)if(dp[cur][u-1][prev-1][i]!=-1) 
            temp2[(i+v[cur][u])%k]=dp[cur][u-1][prev-1][i]+v[cur][u];
        rep(i,0,k)temp2[i]=max(temp2[i],dp[cur][u-1][prev-1][i]);
    }
    //if (cur==1 && u==5 && prev==2)DEBUG(suc1),DEBUG(suc2);
    if (suc1==-1 && suc2==-1) return -1;
    if (suc1==-1)rep(i,0,k)dp[cur][u][prev][i]=temp2[i];
    else if (suc2==-1)rep(i,0,k)dp[cur][u][prev][i]=temp1[i];
    else rep(i,0,k)dp[cur][u][prev][i]=max(temp1[i],temp2[i]);
    //if (cur==1 && u==5 && prev==2)rep(i,0,k)DEBUG(temp1[i]);
    dp[cur][u][prev][0]=max(dp[cur][u][prev][0],0);
    return 1;
}

int main(){
    upgrade();
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
    rep(i,1,n+1)rep(j,1,m+1)cin>>v[i][j];
    int ans1[N], ans2[N];
    rep(i,1,n+1){
        cur=i;
        recur(m,m/2);
        if (i==1)rep(j,0,k)ans1[j]=dp[cur][m][m/2][j];
        else{
            memset(ans2,-1,sizeof(ans2));
            rep(j,0,k)rep(s,0,k){
                if (dp[cur][m][m/2][j]!=-1 && ans1[s]!=-1)ans2[(j+s)%k]=max(ans2[(j+s)%k],ans1[s]+dp[cur][m][m/2][j]);
            }
            swap(ans1,ans2);
        }
    }
    //rep(i,0,k)DEBUG(dp[1][m][m/2][i]);
    cout<<max(0,ans1[0])<<nl;
}