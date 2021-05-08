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

const int N=100100;
int n, v[N];
set<PII> s;

int main(){
    upgrade();
    cin>>n;
    rep(i,0,n)cin>>v[i];
    VI t, t2, r;
    int ans=0;
    rep(i,0,n){
        if (i!=0 && v[i-1]==v[i] && (i==n-1 || v[i+1] != v[i])) r.pb(i);
    }
    rep(i,0,n){
        int a;
        a = lower_bound(all(r), i)-r.begin();
        if (i!=n-1 && v[i] == v[i+1]) t.pb(v[i]);
        else if (a != SZ(r) && r[a]==i) t2.pb(v[i]);
        else{
            if (a == SZ(r) || a-1 < 0)t2.pb(v[i]);
            else if (v[i] != v[r[a]] && v[r[a]]==v[r[a-1]] && s.count(mp(r[a-1], r[a]))==0 && (i!=n-1 && v[i-1] != v[i+1])){
                s.insert(mp(r[a-1], r[a]));
                t.pb(v[i]);
            }
            else t2.pb(v[i]);
        }
    }
    rep(i,0,SZ(t)){
        if (i==SZ(t)-1 || t[i] !=t[i+1]) ans++;
    }
    rep(i,0,SZ(t2)){
        if (i==SZ(t2)-1 || t2[i] !=t2[i+1]) ans++;
    }
    cout<<ans<<nl;
}