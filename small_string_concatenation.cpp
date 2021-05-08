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

const int N=50050;
vector<string> v[51];
int n,p[51];

struct str{
    string s;
    const int operator<(str right){
        if (s+right.s < right.s+s)return 1;
        return 0;
    }
};
str v2[N];

int main(){
    upgrade();
    cin>>n;
    rep(i,0,n){
        cin>>v2[i].s;
    }
    sort(v2,v2+n);
    rep(i,0,n)cout<<v2[i].s;
    cout<<nl;
    /*
    rep(i,0,n){
        string str;cin>>str;
        v[SZ(str)].pb(str);
    }
    rep(i,1,51)sort(all(v[i])),p[i]=0;
    int cur;
    string s;
    string ret = "";
    while(1){
        cur=-1;
        rep(i,1,51){
            if (p[i]==SZ(v[i]))continue;
            string temp=v[i][p[i]];
            if (cur==-1 || temp<s){
                s=temp;
                cur=i;
                continue;
            }
            int suc=1;
            rep(j,0,SZ(s)){
                if (temp[j] != s[j])suc=0;
            }
            if (suc){
                suc=1;
                rep(j,SZ(s),SZ(temp)){
                    if (temp[j]==temp[j-SZ(s)])continue;
                    else if (temp[j]>temp[j-SZ(s)]){
                        suc=0;
                        break;
                    }
                    else break;
                }
            }
            if (suc){
                s=temp;
                cur=i;
            }
        }
        if (cur==-1)break;
        ret += v[cur][p[cur]++];
    }
    cout<<ret<<nl;*/
}