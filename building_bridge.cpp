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

const int N=100100;

ll l[N],r[N],lr[N];
double ld[N];
int main(){
    upgrade();
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    rep(i,0,n){
        cin>>l[i];
        ld[i]=sqrt(a*a+l[i]*l[i]);
    }
    rep(i,0,m){
        cin>>r[i];
    }
    rep(i,0,m)cin>>lr[i];
    double ans=DBL_MAX;
    int al,ar;
    rep(i,0,m){
        int opp=r[i]-r[i]*(b-a)/b;
        double temp;
        int p2=upper_bound(l,l+n,opp)-l;
        //DEBUG(p2);
        int p1=p2-1;
        if (p1>=0){
            temp=ld[p1]+sqrt((b-a)*(b-a)+(r[i]-l[p1])*(r[i]-l[p1]))+lr[i];
            //DEBUG(temp);
            if (temp<ans){
                al=p1+1;ar=i+1;
                ans=temp;
            }
        }
        if (p2<n){
            temp=ld[p2]+sqrt((b-a)*(b-a)+(r[i]-l[p2])*(r[i]-l[p2]))+lr[i];
            if (temp<ans){
                al=p2+1;ar=i+1;
                ans=temp;
            }
        }
    }
    cout<<al<<' '<<ar<<nl;
}