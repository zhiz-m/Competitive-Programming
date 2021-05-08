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
int n,m,k,t1,t2;
ll s;
pair<ll,ll> c1[N],c2[N],ex1[N],ex2[N];
int ans[N],temp[N],type[N];


bool solve(int u){
    int p1=0,p2=0;
    ll t=0;
    rep(i,0,k){
        if (p1==t1){
            t+=c2[p2].fi*ex2[u].fi,temp[i]=c2[p2].se,p2++;
            continue;
        }
        else if(p2==t2){t+=c1[p1].fi*ex1[u].fi,temp[i]=c1[p1].se,p1++;continue;}
        ll a=c1[p1].fi*ex1[u].fi,b=c2[p2].fi*ex2[u].fi;
        if (a<b)t+=a,temp[i]=c1[p1].se,p1++;
        else t+=b,temp[i]=c2[p2].se,p2++;
    }
    if (t<=s){
        swap(ans,temp);
        return 1;
    }
    return 0;
}

int main(){
    upgrade();
    cin>>n>>m>>k>>s;
    ex1[0].fi=ex2[0].fi=1e9;
    ex1[0].se=ex2[0].se=0;
    rep(i,1,n+1){
        cin>>ex1[i].fi;
        ex1[i].se=i;
        ex1[i]=min(ex1[i-1],ex1[i]);
    }
    rep(i,1,n+1){
        cin>>ex2[i].fi;
        ex2[i].se=i;
        ex2[i]=min(ex2[i-1],ex2[i]);
    }
    t1=t2=0;
    rep(i,1,m+1){
        int a,b;cin>>a>>b;
        if (a==1)c1[t1].se=i,c1[t1++].fi=b;
        else c2[t2].se=i,c2[t2++].fi=b;
        type[i]=a;
    }
    sort(c1,c1+t1);
    sort(c2,c2+t2);
    if (!solve(n)){
        cout<<-1<<nl;
        return 0;
    }
    int l=0,r=n;
    while(r-l>1){
        int mid=(l+r)/2;
        if (!solve(mid))l=mid;
        else r=mid;
    }
    cout<<r<<nl;
    rep(i,0,k){
        cout<<ans[i]<<' ';
        if (type[ans[i]]==1)cout<<ex1[r].se<<nl;
        else cout<<ex2[r].se<<nl;
    }
}