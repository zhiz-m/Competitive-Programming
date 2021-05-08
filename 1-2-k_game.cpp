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

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        int n,k;cin>>n>>k;
        int f=k%3;
        /*
        if (n<k){
            if (f){
                cout<<"Bob"<<nl;
            }
            else{
                cout<<"Alice"<<nl;
            }
            continue;
        }*/
        if (f==1 || f==2){
            if (n%3==0)
                cout<<"Bob"<<nl;
            else{
                cout<<"Alice"<<nl;
            }
            continue;
        }
        int x=k/3;
        int p=4+3*(x-1);
        n%=p;
        //DEBUG(n),DEBUG(x);
        if (n==p-1){
            cout<<"Alice"<<nl;
        }
        else if (n%3==0){
            cout<<"Bob"<<nl;
        }
        else {
            cout<<"Alice"<<nl;
        }
    }
}