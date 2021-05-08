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

const int N=200200, L=N*20;
int n, a[N], b[N], fen[L],c[N],d[N];

void reset(){
    memset(fen,0,sizeof(fen));
}

void update(int u, int i){
    assert(i!=-1);
    i++;
    while(i<L){
        fen[i]+=u;
        i += i&( -i);
    }
}

int get(int i){
    i++;
    int res=0;
    while(i){
        res+=fen[i];
        i -= i&(-i);
    }
    return res;
}

int main(){
    upgrade();
    cin>>n;
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    //reset();
    //update(1,0);
    //update(20,3);
    //DEBUG(get(10));
    reset();
    rep(i,0,n){
        c[i]=a[i]-get(a[i]);
        
        //DEBUG(c[i]);
        update(1,a[i]);
    }
    reset();
    rep(i,0,n){
        d[i]=b[i]-get(b[i]);
    //    DEBUG(d[i]);
        update(1,b[i]);
    }
    per(i,0,n){
        int mx=n-i;
        c[i]+=d[i];
        if (c[i]>=mx){
            c[i]-=mx;
            if (i!=0)c[i-1]++;
        }
    }
    //rep(i,0,n)DEBUG(c[i]);
    reset();
    rep(i,0,n){
        int l=-1,r=n-1;
        while(r-l>1){
            int md=(l+r)/2;
            assert(md>=0);
            if (md-get(md)>=c[i])r=md;
            else l=md;
        }
        d[i]=r;
        assert(r>=0);
        update(1,d[i]);
    }
    rep(i,0,n)cout<<d[i]<<" \n"[i==n-1];
}