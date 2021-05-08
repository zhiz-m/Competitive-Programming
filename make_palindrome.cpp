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

string s,ans;
int n;
VI v(26);

int main(){
    upgrade();
    cin>>s;
    n=SZ(s);
    rep(i,0,n)v[s[i]-'a']++;
    rep(i,0,26){
        while(v[i]>=2)ans+=('a'+i),v[i]-=2;
    }
    int l=0,r=25;
    while(l<26 && v[l]==0)l++;
    while(r>=0 && v[r]==0)r--;
    while(l<r){
        ans+=(l+'a');
        l++;r--;
        while(l<26 && v[l]==0)l++;
        while(r>=0 && v[r]==0)r--;
    }
    sort(all(ans));
    rep(i,0,SZ(ans))cout<<ans[i];
    if (l==r)cout<<(char)('a'+l);
    per(i,0,SZ(ans))cout<<ans[i];
    cout<<nl;
}