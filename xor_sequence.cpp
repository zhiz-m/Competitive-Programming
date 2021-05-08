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

const int N=110;

template <class T> struct Matrix{
private:
    vector<vector<T>> a;
    ll n,m;
public:
    Matrix(){}
    void reset(int _n){
        n=m=_n;
        a.assign(n,vector<T>(m,0));
    }
    void reset(int _n, int _m){ // down, across
        n=_n,m=_m;
        a.assign(n,vector<T>(m,0));
    }
    void reset(const vector<vector<T>> &_a){
        a=_a;
        n=SZ(a);
        m=SZ(a[0]);
    }
    Matrix(int _n){
        reset(_n);
    }
    Matrix(int _n, int _m){ // down, across
        reset(_n, _m);
    }
    Matrix(const vector<vector<T>> &_a){
        reset(_a);
    }
    int size() const{return n;}
    int height() const{return n;}
    int width() const{return m;}
    vector<vector<T>> get_vector() const{return a;}
    static Matrix I(int k){
        Matrix t(k);
        rep(i,0,k)t[i][i]=1;
        return t;
    }
    const vector<T> &operator[](int i) const{return a.at(i);}
    vector<T> &operator[](int i){return a.at(i);}
    Matrix &operator+=(const Matrix &b){
        assert(n==b.height()&&m==b.width());
        rep(i,0,n)rep(j,0,m)a[i][j]=(a[i][j]+b[i][j])%MOD;// add ...%MOD if necessary
        return (*this);
    }
    Matrix &operator-=(const Matrix &b){
        assert(n==b.height()&&m==b.width());
        rep(i,0,n)rep(j,0,m)a[i][j]=(a[i][j]-b[i][j]+MOD)%MOD;// add (...+MOD)%MOD if necessary
        return (*this);
    }
    Matrix &operator*=(const Matrix &b){
        assert(m==b.height());
        Matrix c(n,b.width());
        rep(i,0,n)
            rep(j,0,b.width())
                rep(k,0,m)
                    c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;// add %MOD if necessary
        *this=c;
        return (*this);
    }
    Matrix &operator^=(ll p){
        assert(n==m);
        Matrix t=I(n);
        if (p==0){
            *this=t;
            return (*this);
        }
        //Matrix pow(*this);
        while(p){
            if (p&1)t*=(*this);
            (*this)*=(*this);
            p>>=1;
        }
        //a=t.get_vector();
        return (*this)=t;
    }
    Matrix operator+(const Matrix &b){
        return (Matrix(*this)+=b);
    }
    Matrix operator-(const Matrix &b){
        return (Matrix(*this)-=b);
    }
    Matrix operator*(const Matrix &b){
        return (Matrix(*this)*=b);
    }
    Matrix operator^(const ll k){
        return (Matrix(*this)^=k);
    }
};

ll n, v[N], k;
Matrix<ll> mt;

int main(){
    upgrade();
    cin>>n>>k;
    mt.reset(n,n);
    rep(i,0,n)cin>>v[i];
    rep(i,0,n)rep(j,0,n){
        ll a = v[i]^v[j];
        int cnt=0; 
        while(a)cnt+=a&1,a>>=1;
        mt[i][j] = cnt%3==0;
    }
    Matrix<ll> base(1,n);
    rep(i,0,n)base[0][i]=1;
    mt^=k-1;
    base*=mt;
    ll ans=0;
    rep(i,0,n)ans=(ans+base[0][i])%MOD;
    cout<<ans<<nl;
}
