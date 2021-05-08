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
int n,m,s[N],d[N],c[N],num[N],ans[N];

int main(){
    upgrade();
    cin>>n>>m;
    rep(i,1,m+1){
        cin>>s[i]>>d[i]>>c[i];
        num[i]=0;
    }
    rep(i,1,n+1){
        ans[i]=0;
        int mn=1e9,cnt=0,t;
        rep(j,1,m+1){
            if (d[j]==i)cnt++;
            if (d[j]==i&&c[j]!=num[j]){
                cout<<-1<<nl;
                return 0;
            }
        }
        if (cnt==1){
            ans[i]=m+1;
            continue;
        }
        rep(j,1,m+1){
            if (num[j]!=c[j] && s[j]<=i && d[j]<mn){
                t=j;
                mn=d[j];
            }
        }
        if (mn!=1e9)num[t]++,ans[i]=t;
    }
    rep(i,1,n+1)cout<<ans[i]<<" \n"[i==n];
}