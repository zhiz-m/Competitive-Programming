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

ll tot[7], c[7], x, y;

void solve(){
    cin>>x>>y;
    rep(i,1,7)cin>>c[i], tot[i]=0;
    if (x>0)tot[6]+=x;
    else tot[3]+=-x;
    if (y>0)tot[2]+=y;
    else tot[5]+=-y;
    rep(i,1,7){
        int l=i-1,r=i+1;
        if (l==0)l=6;
        if (r==7)r=1;
        if (c[i]>c[l]+c[r]){
            int t=tot[i];
            tot[i]=0;
            tot[l]+=t,tot[r]+=t;
        }
        rep(j,1,7){
            int opp = (j+2)%6+1;
            int t=min(tot[j],tot[opp]);
            tot[j]-=t,tot[opp]-=t;
        }
    }   
    rep(i,1,7){
        int l=i-1,r=i+1;
        if (l==0)l=6;
        if (r==7)r=1;
        if (c[i]<c[l]+c[r]){
            int t=min(tot[l],tot[r]);
            tot[i]+=t;
            tot[l]-=t,tot[r]-=t;
        }
        rep(j,1,7){
            int opp = (j+2)%6+1;
            int t=min(tot[j],tot[opp]);
            tot[j]-=t,tot[opp]-=t;
        }
    }
    
    ll ans=0;
    rep(i,1,7)ans+=tot[i]*c[i];
    cout<<ans<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}