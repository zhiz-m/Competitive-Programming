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

const int N=1000100;
int n,m,org[200200];
VI v[N];

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,1,n+1){
        int a;cin>>a;
        v[a].pb(i);
        org[i]=a;
    }
    rep(i,0,m){
        int a,b,x;cin>>a>>b>>x;
        if (org[a]!=x){
            cout<<a<<nl;
            continue;
        }
        if (org[b]!=x){
            cout<<b<<nl;
            continue;
        }
        if (a==b){
            cout<<-1<<nl;
            continue;
        }
        int l=lower_bound(all(v[x]),a)-v[x].begin();
        int r=upper_bound(all(v[x]),b)-v[x].begin();
        int L=l,R=r,mid;
        while(R-L>1){
            mid=(L+R)/2;
            if (mid-l+v[x][l]==v[x][mid]){
                L=mid;
            }
            else R=mid;
        }
        if (R==r)cout<<-1<<nl;
        else cout<<v[x][R]-1<<nl;
    }
}