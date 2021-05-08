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
const ll MOD=1000000007;
mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void upgrade(){ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);}
//head: credit MiFaFaOvO

const int N = 100100;
int n,cnt=1,mx=-1;
VI v(N),pos,neg,m;
vector<VI> dp;

int main(){
    cin>>n;
    rep(i,0,n)cin>>v[i];
    int p1=0,p2=n-1,cur=0;
    while(v[p1]<=0 && p1<n)p1++;
    while(v[p2]<=0 && p2>=0)p2--;
    if (p1>=p2){
        cout<<0<<nl;
        return 0;
    }
    rep(i,p1,p2+1){
        //if (v[p1]>=0)mx=max(mx,v[p1]);
        if (v[i]==0)continue;
        if (i==p1 || (cur>=0 && v[i]>=0)){
            cur+=v[i];
            mx=max(mx,v[i]);
        }
        else if (cur<0 && v[i]<0)cur+=v[i];
        else {
            if (cur>=0){
                pos.pb(cur),cnt++,m.pb(mx),mx=-1;
                //DEBUG(cur);
            }
            else neg.pb(cur),mx=v[i];
            cur=v[i];
        }
        if (i==p2)pos.pb(cur),m.pb(mx);
    }
    //each(i,pos)DEBUG(i);
    //rep(i,0,cnt-1)DEBUG(pos[i]),DEBUG(neg[i]),DEBUG(m[i]);
    dp.assign(cnt,VI(31,-1));
    rep(i,0,cnt){
        dp[i][m[i]]=pos[i];
        if (i==0){
            continue;
        }
        rep(j,0,31){
            if (dp[i-1][j]==-1)continue;
            mx=max(m[i],j);
            int a=dp[i-1][j]+neg[i-1];
            if (a<0)continue;
            //DEBUG(i),DEBUG(j),DEBUG(a);
            dp[i][mx] = max(dp[i][mx],a+pos[i]);
        }
    }/*
    rep(i,0,cnt){
        rep(j,0,31)cout<<dp[i][j]<<' ';
        cout<<nl;
    }*/
    int ans=-1;
    rep(i,0,cnt)rep(j,0,31)ans=max(ans,dp[i][j]-j);
    cout<<ans<<nl;
}