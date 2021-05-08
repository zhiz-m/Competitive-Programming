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
int n,k,l,v[N],d[N][2*N],vk[2*N],s[2*N];

void solve(){
    cin>>n>>k>>l;
    rep(i,0,n){
        cin>>v[i];
    }
    rep(i,0,n+1)s[i]=0;
    rep(i,0,k+1)vk[i]=i;
    rep(i,k+1,2*k)vk[i]=2*k-i;
    rep(i,0,n){
        rep(j,0,2*k){
            d[i][j]=((v[i]+vk[j])<=l);
        }
        rep(j,0,2*k){
            int nx=(j+1)%(2*k);
            if (d[i][j]==0 && d[i][nx]==1)s[i]=nx;
        }
    }
    rep(j,0,2*k)d[n][j]=1;
    //s[n]=0;
    int p=s[0];
    rep(i,0,n){
        int st=(p-1+2*k)%(2*k),suc=0,np=1e9;    
        for(;;p=(p+1)%(2*k)){
            int nx=(p+1)%(2*k);
            if (d[i][p]==0)break;
            if (d[i+1][nx]){
                suc=1;
                if (np==1e9||((nx-s[i+1]+2*k)%(2*k)<(np-s[i+1]+2*k)%(2*k)))np=nx;
            }
            if (p==st)break;
        }
        //DEBUG(1);
        if (suc){
            //DEBUG(np);
            p=np;
        }
        else{
            cout<<"No"<<nl;
            return;
        }
    }
    //DEBUG(2);
    cout<<"Yes"<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}