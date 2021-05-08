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
int n,m,dsu[N],val[N];
tuple<int,int,int> v[N];

int find(int u){
    if (dsu[u]==u)return u;
    return dsu[u]=find(dsu[u]);
}

int search(int u){
    rep(i,1,2*n+1)dsu[i]=i,val[i]=i<=n?-1:1;
    rep(i,1,u+1){
        int a,b,d;
        tie(d,a,b)=v[i];
        b+=n;
        if (find(a)==find(b))continue;
        val[find(a)]+=val[find(b)];
        dsu[find(b)]=find(a);
    }
    rep(i,1,n+1){
        if (val[find(i)]!=0)return 0;
    }
    return 1;
}

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,1,m+1){
        int a,b,d;cin>>a>>b>>d;
        v[i]=make_tuple(d,a,b);
    }
    sort(v+1,v+m+1);
    int l=1,r=m+1,mid;
    rep(i,0,20){
        mid=(l+r)/2;
        if (search(mid))r=mid;
        else l=mid;
        //DEBUG(l),DEBUG(r);
    }
    if (r==m+1)cout<<-1<<nl;
    else cout<<get<0>(v[r])<<nl;
}