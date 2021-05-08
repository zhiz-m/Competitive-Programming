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
    int n;cin>>n;
    int a,b;
    a=b=0;
    VI v(n+2,0);
    rep(i,1,n+1){
        char c;
        cin>>c;
        int x;
        if (c=='('){x=1;a++;}
        else if (c==')'){x=-1;b++;}
        else x=0;
        v[i]=x;
        //DEBUG(v[i]);
    }
    int suc=1;
    if (n%2==1) suc=0;
    else if (a>n/2 || b>n/2)suc=0;
    int cnt=0;
    //DEBUG(suc);
    per(i,2,n+1){
        cnt+=v[i]==1;
        //DEBUG(cnt);
        if (cnt*2>=n-i+1)suc=0;
    }
    cnt=0;
    rep(i,1,n){
        cnt+=v[i]==-1;
        //DEBUG(cnt);
        if (cnt*2>=i)suc=0;
    }
    if (!suc){
        cout<<":("<<nl;
        return 0;
    }
    //DEBUG(a);
    a=n/2-a;
    //DEBUG(a);
    b=n/2-b;
    rep(i,1,n+1){
        //DEBUG(v[i]);
        if (v[i]==1)cout<<'(';
        else if (v[i]==-1)cout<<')';
        else if (a){
            //DEBUG(a);
            a--;
            cout<<'(';
        }
        else{
            b--;
            cout<<')';
        }
    }
    cout<<nl;
}