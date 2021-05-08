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

const int N=3000100, M=27;

int q, v[N], nx[N][2], cnt=2;

int get_next(int i, int dir){
    if (nx[i][dir]!=-1)return nx[i][dir];
    return nx[i][dir] = cnt++;
}

void update(int num, int val){
    int cur=1, b=1<<(M-1);
    //DEBUG(1);
    while(b){
        //DEBUG(cur);
        if (num&b) cur=get_next(cur,1);
        else cur=get_next(cur,0);
        v[cur]+=val;
        b>>=1;
        //DEBUG(2);
    }
    //DEBUG(3);
}

int calc(int p, int u){
    int cur=1, b=1<<(M-1), ret=0, s=0;
    
    while(b){
        //int nx = b>>1;
        if (cur==-1)break;
        int x0=0, x1=1;
        if (p&b){
            swap(x0,x1);
        }
        if (b+s<u){
            if (nx[cur][x0]!=-1)ret+=v[nx[cur][x0]];
            //ret+=v[get_next(cur,x0)];
            s+=b;
            cur = nx[cur][x1];
        }
        else{
            cur = nx[cur][x0];
        }
        b>>=1;
        
    }
    if (b==0 && cur!=-1) ret+=v[cur];
    return ret;
}

int main(){
    upgrade();
    memset(v,0,sizeof(v));
    memset(nx,-1,sizeof(nx));
    cin>>q;
    rep(i,0,q){
        int t;cin>>t;
        if (t==3){
            int p,l;cin>>p>>l;
            cout<<calc(p,l)<<nl;
        }
        else{
            int s=(t==1)*2-1;
            int p;cin>>p;
            update(p,s);
        }
    }
}