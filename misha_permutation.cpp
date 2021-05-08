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
int n, v1[N],v2[N], s1[N],s2[N],dsu[N];
set<int> s;

int find(int u){
    if (s.count(dsu[u])){
        return dsu[u]=find(dsu[u+1]);
    }
    return dsu[u];
}

struct SegmentTree{ //Modify  compare() and compare_lazy()
private: VLL st, v, lazy; // lazy holds new values on a per-range basis
    int n;
    const int MAX_N = 200001; // Modify
    const ll EMPTY = -LLONG_MAX; // Modify. Value that lazy[] will never contain
    const ll INVALID = -LLONG_MAX; // Modify. value that is used for out of range
    int left(int p){return (p<<1);}
    int right(int p){return (p<<1)+1;}
    ll compare(ll a, ll b){return a+b;} // Modify. For finding st values given values of children 
    ll compare_lazy(int L, int R, ll cur, ll nval){ // Modify. For updating st values based on range and current lazy value
        return cur+(R-L+1)*nval; // nval for RMQ. (cur + (R-L+1)*nval) for sum queries. 
    }
    ll update_lazy(ll cur, ll nval){ // Modify. This function updates individual lazy values given the lazy value for parent
        if (cur==EMPTY) return nval; 
        return nval+cur; 
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

int main(){
    upgrade();
    cin>>n;
    rep(i,0,n)cin>>v1[i];
    rep(i,0,n)cin>>v2[i];
    SegmentTree t1,t2;
    rep(i,0,n){
        dsu[i]=i;
        //DEBUG(i);
        //DEBUG(t1.get(v1[i],v1[i]));
        s1[i]=v1[i]-t1.get(v1[i],v1[i]);
        //DEBUG(v1[i]);
        t1.update(v1[i],n-1,1);
        //DEBUG(s1[i]);
    }
    rep(i,0,n){
        s2[i]=v2[i]-t2.get(v2[i],v2[i]);
        t2.update(v2[i],n-1,1);
    }
    per(i,0,n){
        s1[i]+=s2[i];
        if (s1[i]>=n-i){
            s1[i]-=n-i;
            //assert(i!=0);
            if (i!=0)s1[i-1]++;
        }
        //DEBUG(s1[i]);
    }
    rep(i,0,n){
        DEBUG(s1[i]);
        int t=find(s1[i]);
        s.insert(t);
        cout<<t<<' ';
    }
    cout<<nl;
}