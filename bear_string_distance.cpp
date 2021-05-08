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
int n, v[N],ret[N],k;

int main(){
    upgrade();
    cin>>n>>k;
    string s;cin>>s;
    rep(i,0,n)v[i]=s[i]-'a';
    rep(i,0,n){
        if (k==0){
            ret[i]=v[i];
            continue;
        }
        if (k<26){
            rep(j,0,26){
                if (abs(j-v[i])==k){
                    ret[i]=j;
                    k=0;
                    break;
                }
            }
        }
        if (k==0)continue;
        if (v[i]<13){
            ret[i]=25;
            k-=25-v[i];
        }
        else{
            ret[i]=0;
            k-=v[i];
        }
    }
    if (k!=0) cout<<-1<<nl;
    else {rep(i,0,n)cout<<(char)('a'+ret[i]);
    cout<<nl;}
}