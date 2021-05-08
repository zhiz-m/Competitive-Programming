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

const int N=2010;
ll n,c[N],k[N],x[N],y[N],dsu[N];
vector<tuple<ll,ll,ll>> pq;

vector<PII> e; 
VI p;

ll find(int u){
    if (dsu[u]==u)return u;
    return dsu[u] = find(dsu[u]);
}

int main(){
    upgrade();
    cin>>n;
    rep(i,1,n+1)cin>>x[i]>>y[i];
    rep(i,1,n+1)cin>>c[i], pq.pb(make_tuple(c[i],-1,i));
    rep(i,1,n+1)cin>>k[i];
    rep(i,1,n+1)dsu[i]=i;
    rep(i,1,n+1)rep(j,i+1,n+1){
        pq.pb(make_tuple((abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]),i,j));
    }
    sort(all(pq));
    ll cost=0;
    each(i,pq){
        ll w,a,b;
        tie(w,a,b)=i;
        //DEBUG(w),DEBUG(a),DEBUG(b);
        if (a == -1){
            if (find(b)==0)continue;
            dsu[find(b)]=0;
            cost+=w;
            p.pb(b);
        }
        else{
            if (find(a) == find(b)) continue;
            if (find(b)==0) swap(a,b);
            dsu[find(b)] = find(a);
            cost+=w;
            e.pb(mp(a,b));
        }
    }
    cout<<cost<<nl;
    cout<<SZ(p)<<nl;
    each(i,p)cout<<i<<" ";
    cout<<nl<<SZ(e)<<nl;
    each(i,e)cout<<i.fi<<" "<<i.se<<nl;
}