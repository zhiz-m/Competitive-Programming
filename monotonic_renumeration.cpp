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
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n'
#define nl '\n'
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef long long ll;
const ll MOD=998244353;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

VI a;
vector<bool> done;
vector<PII> s;
VI v1,v2; //array numbers, last appearing index

int main(){
    upgrade();
    int n;cin>>n;
    a.resize(n);
    done.assign(n,false);
    rep(i,0,n){
        cin>>a[i];
        s.pb(mp(a[i],i));
    }
    sort(all(s));
    s.pb(mp(-1,-1));
    rep(i,1,n+1){
        if (s[i].fi!=s[i-1].fi){
            v1.pb(s[i-1].fi);
            v2.pb(s[i-1].se);
            //DEBUG(s[i-1].fi),DEBUG(s[i-1].se);
        }
    }
    ll ans=1;
    int p=-1;
    rep(i,0,n){
        if (done[i]) continue;
        if (i>=p && i!=0)ans=ans*2%MOD;
        int ind=lower_bound(all(v1),a[i])-v1.begin();
        p=max(v2[ind],p);
        done[p]=true;
        //DEBUG(i),DEBUG(v2[ind]);
        //DEBUG(a[i]),DEBUG(i),DEBUG(p);
    }
    cout<<ans<<nl;
}