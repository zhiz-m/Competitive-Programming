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
const int N=200200;
int a[N],b[N],c[N],d[N],p1,p2,p3,p4;

int main(){
    int n,k;scanf("%d %d",&n,&k);
    p1=p2=p3=p4=0;
    a[0]=b[0]=c[0]=d[0]=0;
    rep(i,0,n){
        int t,u,v;scanf("%d %d %d",&t,&u,&v);
        if (u && v)a[++p1]=t;
        else if (u)b[++p2]=t;
        else if (v)c[++p3]=t;
    }
    sort(a,a+p1+1);
    sort(b,b+p2+1);
    sort(c,c+p3+1);
    p2=min(p2,p3);
    rep(i,1,p1+1){
        a[i]=a[i-1]+a[i];
    }
    rep(i,1,p2+1){
        d[i]=d[i-1]+b[i]+c[i];
    }
    if (p1+p2<k)puts("-1");
    else{
        p1=min(k,p1);
        p2=min(k,p2);
        int ans=2e9;
        rep(i,k-p1,p2+1){
            ans=min(ans,a[k-i]+d[i]);
        }
        printf("%d\n",ans);
    }
}