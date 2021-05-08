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
const ll MOD=998244353;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

VLL v,s;

int get_s(ll num){
    //DEBUG(num);
    int cnt=0;
    while(num){
        num/=10;
        cnt++;
    }
    //DEBUG(cnt);
    return cnt;
}
ll calc(ll num, int d){
    //DEBUG(num),DEBUG(d);
    ll ret=0;
    ll c=1;
    rep(i,0,d){
        ll temp=num%10;
        temp*=c;
        ret+=temp;
        c*=100;
        num/=10;
    }
    //DEBUG(ret);
    return ret%MOD;
}
ll get_c(ll num, int d){ //amount of digits used already
    //DEBUG(num),DEBUG(d);
    ll c=100;
    rep(i,0,d){
        num/=10;
    }
    d--;
    ll ret=0;
    while(d){
        c*=100,d--;
    }
    while(num){
        ll temp=num%10;
        temp*=c;
        ret+=temp;
        num/=10;
        c*=10;
    }
    //DEBUG(ret);
    return ret%MOD;
}

int main(){
    upgrade();
    ll n;cin>>n;
    v.resize(n);
    s.assign(11,0);
    rep(i,0,n){
        cin>>v[i];
        s[get_s(v[i])]++;
    }
    ll ans=0;
    //rep(i,1,11)DEBUG(s[i]);
    rep(i,0,n){
        int d=get_s(v[i]);
        rep(j,1,d+1){
            if(s[j]==0) continue;
            ll t = calc(v[i],j)*s[j]%MOD;
            ll c = get_c(v[i],j)*s[j]%MOD;
            t=t*11%MOD;
            c=c*2%MOD;
            ans=(ans+c+t)%MOD;
            // second
            /*t=t*10%MOD;
            c=c*10%MOD;
            ans=(ans+c+t)%MOD;*/
        }
        rep(j,d+1,11){
            if(s[j]==0) continue;
            ll t = calc(v[i],d)*s[j]%MOD;
            t=t*11%MOD;
            ans=(ans+t)%MOD;
        }
    }
    cout<<ans<<nl;
}