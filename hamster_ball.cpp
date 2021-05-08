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
int t,b;
PII v[N];

int main(){
    upgrade();
    double pi = 3.1415;
    cin>>t>>b;
    rep(i,0,b){
        int d,s;cin>>s>>d;
        v[i]=mp(d,s);
    }
    sort(v,v+b);
    int ans=0;
    double cur=t;
    rep(i,0,N){
        double d = pi * v[i].fi * 2;
        //DEBUG(d), DEBUG(i), DEBUG(v[i]);
        if (d*v[i].se <= cur) ans+=v[i].se,cur-=d*v[i].se;
        else{
            ans+=cur/d;
            break;
        } 
    }
    cout<<ans<<nl;
}