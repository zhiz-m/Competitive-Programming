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

const int M=70000, N=20;
int n, x[N], y[N],suc=1,cnt=1;
double dp[M];

double d(int a, int b){
    double ans = sqrt((double)(x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));

    //DEBUG(a),DEBUG(b),DEBUG(ans);
    return ans;
}

double recur(int bits){
    if (bits==0) return 0;
    if (dp[bits]!=-1) return dp[bits];
    double ans=1e9;
    int i,a,j,b;
    for(i=1,a=0;a<2*n;i<<=1,a++){
        if ((bits&i)!=0)break;  
    }
    for(j=i<<1,b=a+1;b<2*n;j<<=1,b++){
        if ((bits &j)==0)continue;
        ans=min(ans,d(a,b)+recur(bits^i^j));
    }
    return dp[bits] = ans;
}

void solve(){
    cin>>n;
    if (n==0){
        suc=0;
        return;
    }
    rep(i,0,2*n){
        string s;
        cin>>s>>x[i]>>y[i];
    }
    rep(i,0,1<<(2*n))dp[i]=-1;
    cout<<"Case "<<cnt++<<": "<<recur((1<<(2*n))-1)<<nl;
}

int main(){
    upgrade();
    cout<<fixed<<setprecision(2);
    while(suc)solve();
}