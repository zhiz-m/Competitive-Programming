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

int check(char c){
    if (c=='{'||c=='<'||c=='('||c=='[')return 0;
    return 1;
}

int main(){
    upgrade();
    int n;string str;stack<char> q;
    cin>>str;n=SZ(str);
    int ans=0;
    rep(i,0,n){
        char c=str[i];
        if (check(c)==0)q.push(c);
        else if (check(c)==1 && q.empty()){
            cout<<"Impossible"<<nl;
            return 0;
        }
        else if ((c==')'&&q.top()=='(')||c-2==q.top()){
            q.pop();
        }
        else {
            ans++;q.pop();
        }
    }
    if (!q.empty())cout<<"Impossible"<<nl;
    else cout<<ans<<nl;
}