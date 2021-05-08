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
struct SegmentTree{ //Modify  compare() and compare_lazy()
private: VLL st, v, lazy; // lazy holds new values on a per-range basis
    int n;
    const int MAX_N = 400100; // Modify
    const ll EMPTY = -LLONG_MAX; // Modify. Value that lazy[] will never contain
    const ll INVALID = -LLONG_MAX; // Modify. value that is used for out of range
    int left(int p){return (p<<1);}
    int right(int p){return (p<<1)+1;}
    ll compare(ll a, ll b){return a|b;} // Modify. For finding st values given values of children 
    ll compare_lazy(int L, int R, ll cur, ll nval){ // Modify. For updating st values based on range and current lazy value
        return 1ll<<nval; // nval for RMQ. (cur + (R-L+1)*nval) for sum queries. 
    
    }
    ll update_lazy(ll cur, ll nval){ // Modify. This function updates individual lazy values given the lazy value for parent
        if (cur==EMPTY) return nval; 
        return nval;
    } 
    void build(int p, int L, int R){
        lazy[p]=EMPTY;
        if (L==R) st[p]=v[L];
        else{
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            st[p]=compare(st[left(p)],st[right(p)]); 
        }
    }
    ll get(int p, int L, int R, int b1, int b2){
        if (b2<L || b1>R) return INVALID;
        if (lazy[p]!=EMPTY){
            st[p]=compare_lazy(L,R,st[p],lazy[p]);
            if (L!=R){
                lazy[left(p)]  = update_lazy(lazy[left(p)] ,lazy[p]);
                lazy[right(p)] = update_lazy(lazy[right(p)],lazy[p]);
            }
            lazy[p]=EMPTY;
        }
        if (L>=b1 && R<=b2) return st[p];
        ll r1 = get(left(p),L,(L+R)/2,b1,b2);
        ll r2 = get(right(p),(L+R)/2+1,R,b1,b2);
        if (r1 == INVALID) return r2;
        if (r2 == INVALID) return r1;
        return compare(r1,r2); 
    }
    void update(int p, int L, int R, int b1, int b2, ll val){
        if (lazy[p]!=EMPTY){
            st[p] = compare_lazy(L,R,st[p],lazy[p]); 
            if (L!=R){
                lazy[left(p)]  = update_lazy(lazy[left(p)] ,lazy[p]);
                lazy[right(p)] = update_lazy(lazy[right(p)],lazy[p]);
            }
            lazy[p]=EMPTY;
        }
        if (b1>R || L>b2) return;
        if (L>=b1 && R<=b2){
            st[p] = compare_lazy(L,R,st[p],val);
            if (L!=R){
                lazy[left(p)]  = update_lazy(lazy[left(p)] ,val);
                lazy[right(p)] = update_lazy(lazy[right(p)],val);
            }
            return;
        }
        update(left(p),L,(L+R)/2,b1,b2,val);
        update(right(p),(L+R)/2+1,R,b1,b2,val);
        st[p]=compare(st[left(p)],st[right(p)]);
    }
public:
    SegmentTree(){
        st.assign(4*MAX_N,0);
        lazy.assign(4*MAX_N,EMPTY);
        n = MAX_N;
    }
    template <class G>void reset(const VLL &_v){
        v=_v;
        build(1,0,n-1);
    }
    ll get(int a, int b){
        return get(1,0,n-1,a,b);
    }
    void update(int L, int R, ll val){
        update(1,0,n-1,L,R,val);
    }
    void update(int a, ll val){
        update(1,0,n-1,a,a,val);
    }
};

const int N=400400;
int n,m,c[N],l[N],r[N],cnt;
VI adj[N];
queue<int> q; //l,r,c;
SegmentTree st;

void dfs(int u, int prev){
    l[u]=cnt++;
    q.push(u);
    each(i,adj[u]){
        if (i==prev)continue;
        dfs(i,u);
    }
    r[u]=cnt;
}

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,1,n+1)cin>>c[i];
    rep(i,1,n){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cnt=1;
    dfs(1,-1);
    while(!q.empty()){
        int u=q.front();
        //DEBUG(u);DEBUG(l[u]),DEBUG(r[u]),DEBUG(c[u]);
        st.update(l[u],r[u]-1,c[u]);
        q.pop();
    }
    rep(i,0,m){
        int a,u;cin>>a>>u;
        if (a==1){
            int col;cin>>col;
            st.update(l[u],r[u]-1,col);
        }
        else{
            int t=0;
            ll b=st.get(l[u],r[u]-1);
            while(b!=0){
                t+=b&1;
                b>>=1;
            }
            cout<<t<<nl;
        }
    }
}