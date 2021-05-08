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

const int N=300100;
ll n,m;
VLL v[4];

ll get_one(int c){
    if (c>=SZ(v[1])) return v[1].back();
    return v[1][c];
}

ll get(int c){
    int l=0,r=min(SZ(v[2]),c/2+1);
    while(r-l>1){
        int mid=(r+l)/2;
        int cur=c-mid*2;
        if (v[2][mid]+get_one(cur)>=v[2][mid-1]+get_one(cur+2)){
            l=mid;
        }
        else r=mid;
    }
    return v[2][l]+get_one(c-l*2);
}

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,1,4)v[i].pb(0);
    rep(i,1,n+1){
        int a,b;cin>>a>>b;
        v[a].pb(b);
    }
    rep(i,1,4)sort(v[i].begin()+1,v[i].end(), greater<int>());
    rep(i,1,4){
        rep(j,1,SZ(v[i]))v[i][j]+=v[i][j-1];
    }
    ll ans=0;
    rep(i,0,SZ(v[3])){
        if (m-i*3<0) break;
        ans=max(ans,v[3][i]+get(m-i*3));
    }
    cout<<ans<<nl;
}