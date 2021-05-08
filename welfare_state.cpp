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
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

VI suf,b; // suffix vector with values, binary search vector 
vector<PII> v;//index, balance

int main(){
    upgrade();
    int n;cin>>n;
    v.assign(n+1,mp(0,0));
    rep(i,1,n+1){
        cin>>v[i].se;
    }
    int q;cin>>q;
    rep(i,1,q+1){
        int f;cin>>f;
        if (f==1){
            int p,x;cin>>p>>x;
            v[p]=mp(i,x);
        }
        else{
            int x;cin>>x;
            b.pb(i);
            suf.pb(x);
        }
    }
    per(i,0,SZ(suf)-1){
        suf[i]=max(suf[i],suf[i+1]);
    }
    rep(i,1,n+1){
        int p=upper_bound(all(b),v[i].fi)-b.begin();
        //DEBUG(p);
        if(p==SZ(suf))cout<<v[i].se<<' ';
        else cout<<max(v[i].se,suf[p])<<' ';
    }
}