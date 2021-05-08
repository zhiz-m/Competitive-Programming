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
private: vector<T> st, v, lazy; // lazy holds new values on a per-range basis
    int n;
    const T MAX_N = 2010; // Modify
    const T EMPTY = INT_MIN; // Modify. Value that lazy[] will never contain
    const T INVALID = INT_MIN; // Modify. value that is used for out of range
    int left(int p){return (p<<1);}
    int right(int p){return (p<<1)+1;}
    T compare(T a, T b){return min(a,b);} // Modify. For finding st values given values of children 
    T compare_lazy(T L, T R, T cur, T nval){ // Modify. For updating st values based on range and current lazy value
        return nval; // nval for RMQ. (cur + (R-L+1)*nval) for sum queries. 
    }
    T update_lazy(T cur, T nval){ // Modify. This function updates individual lazy values given the lazy value for parent
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
    T get(int p, int L, int R, int b1, int b2){
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
        T r1 = get(left(p),L,(L+R)/2,b1,b2);
        T r2 = get(right(p),(L+R)/2+1,R,b1,b2);
        if (r1 == INVALID) return r2;
        if (r2 == INVALID) return r1;
        return compare(r1,r2); 
    }
    void update(int p, int L, int R, int b1, int b2, T val){
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
    }
    template <class G>void reset(const vector<G> &_v){
        v=vector<T>(all(_v)); n = SZ(v);
        build(1,0,n-1);
    }
    T get(int a, int b){
        return get(1,0,n-1,a,b);
    }
    void update(int L, int R, T val){
        update(1,0,n-1,L,R,val);
    }
    void update(int a, T val){
        update(1,0,n-1,a,a,val);
    }
};

int main(){
    upgrade();
    int n,m;cin>>n>>m;
    SegmentTree<int> st;
    VI v(2*n+5,0);
    vector<PII> s,u; // sorted, unsorted
    //rep(i,0,n)cin>>v[i];
    st.reset(v);
    //DEBUG(n);
    rep(i,0,m){
        int t,l,r;cin>>t>>l>>r;
        l=2*l-1;
        r=2*r-1;
        if (t) s.pb(mp(l,r));
        else u.pb(mp(l,r));
    }
    //DEBUG(n);
    rep(i,0,SZ(s)){
        st.update(s[i].fi,s[i].se,1);
    }
    //DEBUG(n);
    rep(i,0,SZ(u)){
        int t=st.get(u[i].fi,u[i].se);
        if (t==1){
            cout<<"NO"<<nl;
            return 0;
        }
    }
    ll cnt=1;
    //bool f=0;
    int mn=0;
    //DEBUG(n);
    rep(j,1,n+1){
        int i=j*2-1;
        if (st.get(i,i)==0 || st.get(i-1,i-1)==0){
            //f=1;
            cnt--;
        }
        else {
            //if (f==1)cnt--;
            //else 
            cnt++;
            //f=0;
        }
        v[i]=cnt;
        //DEBUG(i),DEBUG(cnt);
        mn=min(mn,v[i]);
    }
    //DEBUG(n);
    cout<<"YES"<<nl;
    //rep(i,0,2*n+1) DEBUG(i),DEBUG(st.get(i,i));
    rep(j,1,n+1){
        int i=j*2-1;
        cout<<v[i]+1-mn<<' ';
    }
    cout<<nl;
    //DEBUG(n);
}