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
int n;
string a,b;
VI suf,pref;

int main(){
    upgrade();
    cin>>a>>b;
    n=SZ(a);
    int p=0;
    rep(i,0,SZ(b)){
        while(p<n && a[p] != b[i]) p++;
        if (p == n) break;
        pref.pb(p++);
    }
    p=n-1;
    per(i,0,SZ(b)){
        while(p>=0 && a[p] != b[i]) p--;
        if (p<0) break;
        suf.pb(p--);
    }
    reverse(all(suf));
    int x,y;
    x=0;
    y=SZ(suf);
    rep(i,0,SZ(pref)){
        int l=pref[i],j;
        auto t=upper_bound(all(suf), l);
        j=suf.end()-t;
        j=min(j,SZ(b)-i-1);
        if (i+j+1 > x+y){
            x=i+1,y=j;
            //DEBUG(x),DEBUG(y);
        }
    }
    rep(i,0,x)cout<<b[i];
    rep(i,SZ(b)-y,SZ(b))cout<<b[i];
    if (x==0 && y==0)cout<<"-";
    cout<<nl;
}