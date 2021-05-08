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

const int N = 1100;
VI v(N),cur(N);
void solve(){
    int n;cin>>n;
    int mx=-1;
    rep(i,0,n){
        cin>>v[i];
        mx=max(v[i],mx);
    }
    sort(v.begin(),v.begin()+n);
    //rep(i,0,3)DEBUG(v[i]);
    rep(b,1,2*mx){
        rep(i,0,n){
            cur[i]=v[i]^b;
        }
        sort(cur.begin(),cur.begin()+n);
        bool suc=1;
        rep(i,0,n){
            if (v[i]!=cur[i])suc=0;
        }
        if (suc){
            cout<<b<<nl;
            return;
        }
    }
    cout<<-1<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}