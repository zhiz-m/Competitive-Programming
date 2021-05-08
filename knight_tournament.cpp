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

VI ans;
int n,m;

template <class T=int> class SegmentTree{ //Modify  compare() and compare_lazy()
private: vector<T> st, v, lazy; // lazy holds new values on a per-range basis
    int n;
    const T MAX_N = 300010; // Modify
    const T EMPTY = INT_MIN; // Modify. Value that lazy[] will never contain
    const T INVALID = INT_MIN; // Modify. value that is used for out of range
    int left(int p){return (p<<1);}
    int right(int p){return (p<<1)+1;} // -2 means defeated, -1 undetermined
    T compare(T a, T b){
        if (a==-2 && b==-2) return -2;
        else return -1;

    } // Modify. For finding st values given values of children 
    void build(int p, int L, int R){
        if (L==R) st[p]=v[L];
        else{
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            st[p]=compare(st[left(p)],st[right(p)]); 
        }
    }/*
    T get(int p, int L, int R, int b1, int b2){
        if (b2<L || b1>R) return INVALID;
        if (L>=b1 && R<=b2) return st[p];
        T r1 = get(left(p),L,(L+R)/2,b1,b2);
        T r2 = get(right(p),(L+R)/2+1,R,b1,b2);
        if (r1 == INVALID) return r2;
        if (r2 == INVALID) return r1;
        return compare(r1,r2); 
    }*/
    void update(int p, int L, int R, int b1, int b2, T val){
        if (b1>R || L>b2) return;
        if (st[p]==-2) return;
        if (L==R && L!=val-1){
            ans[L+1]=val;
            st[p]=-2;
            return;
        }
        update(left(p),L,(L+R)/2,b1,b2,val);
        update(right(p),(L+R)/2+1,R,b1,b2,val);
        st[p]=compare(st[left(p)],st[right(p)]);
    }
public:
    SegmentTree(){
        st.assign(4*MAX_N,-1);
        lazy.assign(4*MAX_N,EMPTY);
    }
    template <class G>void reset(const vector<G> &_v){
        v=vector<T>(all(_v)); n = SZ(v);
        build(1,0,n-1);
    }/*
    T get(int a, int b){
        return get(1,0,n-1,a,b);
    }*/
    void update(int L, int R, T val){
        update(1,0,n-1,L,R,val);
    }
};

int main(){
    upgrade();
    cin>>n>>m;
    VI a(n);
    ans.assign(n+1,0);
    //rep(i,0,n)cin>>a[i];
    SegmentTree st;
    st.reset(a);
    int l,r,x;
    //DEBUG('h');
    rep(i,0,m){
        cin>>l>>r>>x;
        l--;r--;x--;
        if (x==l)st.update(l+1,r,x+1);
        else if (x==r)st.update(l,r-1,x+1);
        else {
            st.update(l,x-1,x+1);
            st.update(x+1,r,x+1);
        }
    }
    rep(i,1,n+1)cout<<ans[i]<<' ';
    cout<<nl;
}