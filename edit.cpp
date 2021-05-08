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
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

template <class T> class Matrix{
private:
    vector<vector<T>> a;
    ll m,n;
public:
    Matrix(){}
    Matrix(int _m){
        m=m=_m;
        a.assign(m,vector<T>(n,0));
    }
    Matrix(int _m, int _n){ // down, across
        m=_m,n=_n;
        a.assign(n,vector<T>(n,0));
    }
    Matrix(const vector<vector<T>> &_a){
        a=_a;
        m=SZ(a);
        n=SZ(a[0]);
    }
    int size() const{return m;}
    int height() const{return m;}
    int width() const{return n;}
    vector<vector<T>> get_vector() const{return a;}
    static Matrix I(int k){
        Matrix t(k);
        rep(i,0,k)t[i][i]=1;
        return t;
    }
    const vector<T> &operator[](int i) const{return a.at(i);}
    vector<T> &operator[](int i){return a.at(i);}
    Matrix &operator+=(const Matrix &b){
        assert(m==b.height()&&n==b.width());
        rep(i,0,m)rep(j,0,n)a[i][j]=(a[i][j]+b[i][j]);// add ...%MOD if necessary
        return (*this);
    }
    Matrix &operator-=(const Matrix &b){
        assert(m==b.height()&&n==b.width());
        rep(i,0,m)rep(j,0,n)a[i][j]=(a[i][j]-b[i][j]);// add (...+MOD)%MOD if necessary
        return (*this);
    }
    Matrix &operator*=(const Matrix &b){
        assert(n==b.height());
        Matrix c(m,b.width());
        rep(i,0,m)
            rep(j,0,b.width())
                rep(k,0,n)
                    c[i][j]=(c[i][j]+a[i][k]*b[k][j]);// add %MOD if necessary
        *this=c;
        return (*this);
    }
    Matrix &operator^=(ll p){
        assert(m==n);
        Matrix t=I(m);
        if (p==0){
            *this=t;
            return (*this);
        }
        Matrix pow(*this);
        while(p){
            if (p&1)t*=(*this);
            (*this)*=(*this);
            p>>=1;
        }
        a=t.get_vector();
        return (*this);
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