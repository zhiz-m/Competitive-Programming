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
const ll MOD=998244353;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

template <class T> class Matrix{
private:
    vector<vector<T>> a;
    ll n,m;
public:
    Matrix(){}
    Matrix(int _n){
        n=m=_n;
        a.assign(n,vector<T>(m,0));
    }
    Matrix(int _n, int _m){ // down, across
        n=_n,m=_m;
        a.assign(n,vector<T>(m,0));
    }
    Matrix(const vector<vector<T>> &_a){
        a=_a;
        n=SZ(a);
        m=SZ(a[0]);
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
        rep(i,0,n)rep(j,0,m)a[i][j]=(a[i][j]+b[i][j])%MOD;
        return (*this);
    }
    Matrix &operator-=(const Matrix &b){
        assert(n==b.height()&&m==b.width());
        rep(i,0,n)rep(j,0,m)a[i][j]=(a[i][j]-b[i][j]+MOD)%MOD;
        return (*this);
    }
    Matrix &operator*=(const Matrix &b){
        assert(m==b.height());
        Matrix c(n,b.width());
        rep(i,0,n)
            rep(j,0,b.width())
                rep(k,0,m)
                    c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;
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

int main(){
    upgrade();
    ll n,m,l,r;cin>>n>>m>>l>>r;
    if ((n*m)%2==1){cout<<powmod(r-l+1,n*m)<<nl;return 0;}
    ll E,O;
    E=(r-l+1)/2;
    O=r-l+1-E;
    Matrix<ll> mat(2);
    mat[0]={E,O};
    mat[1]={O,E};
    mat^=n*m;
    //cout<<'h'<<nl;
    //DEBUG(E),DEBUG(O),DEBUG(n*m);
    cout<<mat[0][0]<<nl;
}