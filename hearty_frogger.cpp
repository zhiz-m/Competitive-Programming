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

template <class T> struct SegmentTree{ //Modify  compare() and compare_lazy()
private: vector<T> st, v, lazy; // lazy holds new values on a per-range basis
    int n;
    const T MAX_N = N; // Modify
    const T EMPTY = -LLONG_MAX; // Modify. Value that lazy[] will never contain
    const T INVALID = -LLONG_MAX; // Modify. value that is used for out of range
    int left(int p){return (p<<1);}
    int right(int p){return (p<<1)+1;}
    T compare(T a, T b){return max(a,b);} // Modify. For finding st values given values of children 
    T compare_lazy(T L, T R, T cur, T nval){ // Modify. For updating st values based on range and current lazy value
        return nval+cur; // nval for RMQ. (cur + (R-L+1)*nval) for sum queries. 
    }
    T update_lazy(T cur, T nval){ // Modify. This function updates individual lazy values given the lazy value for parent
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
    void reset(int b){
        n = b;
        v.assign(n,0);
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

int b,p,q;
vector<VI> query(3*N,VI(4)), truck(3*N,VI(4)); //y, x, (l/t1), (h/t2)
SegmentTree<ll> st;

int main(){
    upgrade();
    cin>>b>>p>>q;
    st.reset(b);
    rep(i,0,p){
        cin>>truck[i][1]>>truck[i][0]>>truck[i][2]>>truck[i][3];
    }
    rep(i,0,q){
        cin>>query[i][1]>>query[i][0]>>query[i][2]>>query[i][3];
    }
    sort(query.begin(),query.begin()+q,greater<VI>());
    sort(truck.begin(),truck.begin()+p,greater<VI>());
    ll ans=-1;
    int p1=0,p2=0;
    per(y,0,b){
        while(p1<b&&truck[p1][0]==y){
            int l,r;
            l=truck[p1][1],r=truck[p1][1]+truck[p1][2]-1;
            l=(l+y+b)%b,r=(r+y+b)%b;
            //DEBUG(l),DEBUG(r),DEBUG(truck[p1][3]);
            if (l<=r){
                st.update(l,r,truck[p1][3]);
            }
            else{
                st.update(0,r,truck[p1][3]);
                st.update(l,b-1,truck[p1][3]);
            }
            p1++;
        }
        while(p2<b&&query[p2][0]==y){
            int l,r;
            l=query[p2][1]-query[p2][2],r=query[p2][1]-query[p2][3];
            l=(l+y)%b,r=(r+y)%b;
            l+=(l<0?b:0);
            r+=(r<0?b:0);
            swap(l,r);
            if (query[p2][3]-query[p2][2]>=b)ans=max(ans,st.get(0,b-1));
            if (l<=r){
                ans=max(ans,st.get(l,r));
            }
            else{
                ans=max(ans,st.get(0,l));
                ans=max(ans,st.get(r,b-1));
            }
            p2++;
        }
    }
    cout<<ans<<nl;
}