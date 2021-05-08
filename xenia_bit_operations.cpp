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

template <class T> class SegmentTree{ //Modify  compare() and compare_lazy()
private: vector<T> st, v; // lazy holds new values on a per-range basis
    int n;
    const T MAX_N = (1<<17)+1; // Modify
    const T INVALID = -INT_MAX; // Modify. value that is used for out of range
    int left(int p){return (p<<1);}
    int right(int p){return (p<<1)+1;}
    T compare(T a, T b,bool f){
        return f ? a|b : a^b;
    } // Modify. For finding st values given values of children 
    void build(int p, int L, int R, bool f){
        if (L==R) st[p]=v[L];
        else{
            build(left(p),L,(L+R)/2,!f);
            build(right(p),(L+R)/2+1,R,!f);
            st[p]=compare(st[left(p)],st[right(p)],f); 
        }
    }
    void update(int p, int L, int R, int b1, int b2, T val, bool f){
        if (b1>R || L>b2) return;
        if (L==R) {st[p]=val;return;}
        update(left(p),L,(L+R)/2,b1,b2,val, !f);
        update(right(p),(L+R)/2+1,R,b1,b2,val,!f);
        st[p]=compare(st[left(p)],st[right(p)],f);
    }
public:
    SegmentTree(){
        st.assign(4*MAX_N,0);
    }
    template <class G>void reset(const vector<G> &_v, bool f){
        v=vector<T>(all(_v)); n = SZ(v);
        build(1,0,n-1,f);
    }
    void update(int a, T val,bool f){
        update(1,0,n-1,a,a,val,f);
    }
    T get_ans(){
        return st[1];
    }
};

int main(){
    upgrade();
    int n,m;cin>>n>>m;
    SegmentTree<int> st;
    int mx=4*(1<<n);
    VI a(mx/4);
    rep(i,0,mx/4)cin>>a[i];
    st.reset(a,n%2);
    //DEBUG(st.get_vect()[1]);
    int p,b;
    rep(i,0,m){
        cin>>p>>b;
        st.update(p-1,b,n%2);
        cout<<st.get_ans()<<nl;
    }
}