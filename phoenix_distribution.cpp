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

VI v;
vector<VI>ans;

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        int n,k;cin>>n>>k;
        v.assign(26,0);
        ans.assign(k,VI());
        rep(i,0,n){
            char c;cin>>c;
            v[c-'a']++;
            //DEBUG(c-'a');
        }
        //string str;cin>>str;
        //sort(all(str));
        int p=0;
        int ep=k-1;
        rep(i,0,k){
            while(v[p]==0)p++;
            ans[i].pb(p);
            v[p]--;
            //DEBUG(i),DEBUG(p);
        }
        //DEBUG(1);
        int cnt=0;
        rep(i,0,26){
            if (v[i]>0)cnt++;
        }
        //DEBUG(1);
        if(cnt>=2){
            //DEBUG(2);
            int j=0;
            while(j!=26){
                while(j!=26&&v[j]==0)j++;
                if (j==26)break;
                ans[0].pb(j);
                v[j]--;
            }
        }
        else{
            //DEBUG(1);
            rep(i,1,k){
                if (ans[i][0]!=ans[i-1][0]){
                    ep=i-1;
                    //DEBUG(ans[i][0]),DEBUG(ans[i-1][0]);
                    break;
                }
            }
            p=0; int p2=0;
            while(p!=26){
                while(p!=26&&v[p]==0)p++;
                if (p==26)break;
                ans[p2].pb(p);
                v[p]--;
                p2=(p2==ep) ? 0:p2+1;
            }
            //DEBUG(ep);
            //sort(ans.begin(),ans.begin()+ep);
        }
        sort(all(ans));
        for(int u : ans[k-1]){
            cout<<(char)(u+'a');
        }
            //DEBUG(2);
        cout<<nl;
    }
}