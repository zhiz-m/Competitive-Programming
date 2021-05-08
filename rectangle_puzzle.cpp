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
const double PI=3.14159265359;
const double EP=0.000001;

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
    static Matrix eye(int k){
        Matrix t(k);
        rep(i,0,k)t[i][i]=1;
        return t;
    }
    const vector<T> &operator[](int i) const{return a.at(i);}
    vector<T> &operator[](int i){return a.at(i);}
    Matrix &operator+=(const Matrix &B){
        assert(n==B.height()&&m==B.width());
        rep(i,0,n)rep(j,0,m)a[i][j]=(a[i][j]+B[i][j]);// add ...%MOD if necessary
        return (*this);
    }
    Matrix &operator-=(const Matrix &B){
        assert(n==B.height()&&m==B.width());
        rep(i,0,n)rep(j,0,m)a[i][j]=(a[i][j]-B[i][j]);// add (...+MOD)%MOD if necessary
        return (*this);
    }
    Matrix &operator*=(const Matrix &B){
        assert(m==B.height());
        Matrix c(n,B.width());
        rep(i,0,n)
            rep(j,0,B.width())
                rep(k,0,m)
                    c[i][j]=(c[i][j]+a[i][k]*B[k][j]);// add %MOD if necessary
        *this=c;
        return (*this);
    }
    Matrix &operator^=(ll p){
        assert(n==m);
        Matrix t=eye(n);
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
    Matrix operator+(const Matrix &B){
        return (Matrix(*this)+=B);
    }
    Matrix operator-(const Matrix &B){
        return (Matrix(*this)-=B);
    }
    Matrix operator*(const Matrix &B){
        return (Matrix(*this)*=B);
    }
    Matrix operator^(const ll k){
        return (Matrix(*this)^=k);
    }
    Matrix inverse(){
        assert(n==m);
        Matrix A=*this;
        Matrix B=eye(n);
        T c;
        rep(i,0,n){
            int p = -1;
            rep(j,0,n){
                if(-EP>A[j][i] || A[j][i]>EP) p=j; // Modify for doubles (use EP)
            }
            if (p==-1) return Matrix(0);
            swap(A[p],A[i]);
            swap(B[p],B[i]);
            c=A[i][i];
            per(j,0,n){
                B[i][j]/=c;
                A[i][j]/=c;
            }
            rep(j,0,n){
                if (j==i)continue;
                c=A[j][i];
                rep(k,0,n){
                    B[j][k]-=c*B[i][k];
                    A[j][k]-=c*A[i][k];
                }
            }
        }
        return B;
    }
};


int main(){
    upgrade();
    cout<<fixed<<setprecision(10);
    double w,h,a;
    cin>>w>>h>>a;
    if (h>w)swap(h,w);
    if (a>90)a=180-a;
    a=a*PI/180;
    if (a>=2*atan(h/w)-EP){
        cout<<h*h/sin(a)<<nl;
        return 0;
    }
    Matrix<double> l(2);
    Matrix<double> r(2,1);
    l[0][0]=l[1][1]=cos(a)+1;
    l[0][1]=l[1][0]=sin(a);
    r[0][0]=h;
    r[1][0]=w;
    r=l.inverse()*r;
    double x,y;
    x=r[0][0],y=r[1][0];
    cout<<w*h-(x*x+y*y)*sin(a)*cos(a)<<nl;
}