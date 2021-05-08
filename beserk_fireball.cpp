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

const int N=200200;
ll x,k,y,n,m;
int v[N],r[N];
VI ans,l; //1: not larger, 0: larger

int main(){
    upgrade();
    cin>>n>>m>>x>>k>>y;
    rep(i,1,n+1)cin>>v[i];
    rep(i,1,m+1)cin>>r[i];
    r[0]=r[m+1]=-1;
    int cnt=0,p=1,suc=1;
    rep(i,1,n+1){
        int t=max(r[p-1],r[p]);
        if (v[i]==r[p]){
            ans.pb(cnt);
            l.pb(suc);
            cnt=0;
            suc=1;
            p++;
        }
        else cnt++;
        if(v[i]>t){
            suc=0;
        }
    }
    ans.pb(cnt);
    l.pb(suc);
    if (SZ(ans)!=m+1)cout<<-1<<nl;
    else{
        ll res=0;
        rep(j,0,m+1){
            ll i=ans[j];
            if (i<k && l[j]==0){
                cout<<-1<<nl;
                return 0;
            }
            if (l[j]==0){
                res+=x,i-=k;
            }
            res+=(i/k)*min(x,y*k) + i%k*y;
        }
        cout<<res<<nl;
    }
}