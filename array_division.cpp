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
ll n, v[N];
multiset<int> s1,s2;

int main(){
    upgrade();
    cin>>n;
    ll tot=0;
    rep(i,0,n)cin>>v[i],s1.insert(v[i]),tot+=v[i];
    ll cur=0;
    if (tot%2){
        cout<<"NO"<<nl;
        return 0;
    }
    if (s1.count(tot/2)){
        cout<<"YES"<<nl;
        return 0;
    }
    rep(i,0,n){
        cur+=v[i];
        tot-=v[i];
        s1.erase(s1.find(v[i]));
        s2.insert(v[i]);
        if (tot==cur){
            cout<<"YES"<<nl;
            return 0;
        }
        if (tot<cur && s2.count((cur-tot)/2)){
            cout<<"YES"<<nl;
            return 0;
        }  
        if (tot>cur && s1.count((tot-cur)/2)){
            cout<<"YES"<<nl;
            return 0;
        }
    }
    cout<<"NO"<<nl;
}