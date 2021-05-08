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
int n,m,v[N][N],t[3][3];
vector<PII> s2[16],s3[512],s23[64],s32[64];
vector<PII> ans,cur;

void apply(int x, int y, int f){
    rep(i,0,2)rep(j,0,2){
        if (i*2+j==f)continue;
        cur.pb(mp(x+i,y+j));
        t[x+i][y+j]^=1;
    }
}

void solve(){

}

int main(){
    upgrade();
    rep(i,0,16){
        cur.clear();
        rep(x,0,2)rep(y,0,2){
            int b=x*2+y;
            t[x][y]=(i>>(b-1))&1;
        }
        rep(k,0,16){
            int b=i;
            rep(j,0,4){
                if(b&1)apply(0,0,j);
                b>>=1;
            }
            int suc=1;
            rep(x,0,2)rep(y,0,2){
                if (t[x][y]==1)suc=0;
            }
            if (suc){s2[i]=vector<PII>(cur);break;}
        }
    }
    rep(i,0,512){
        cur.clear();
        rep(x,0,2)rep(y,0,2){
            int b=x*2+y;
            t[x][y]=(i>>(b-1))&1;
        }
        rep(k,0,16){
            int b=i;
            rep(j,0,4){
                if(b&1)apply(0,0,j);
                b>>=1;
            }
            int suc=1;
            rep(x,0,2)rep(y,0,2){
                if (t[x][y]==1)suc=0;
            }
            if (suc){s2[i]=vector<PII>(cur);break;}
        }
    }
    int tc;cin>>tc;
    while(tc--)solve();
}