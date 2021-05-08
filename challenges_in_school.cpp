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

const int N = 3030;

int main(){
    upgrade();
    int n,k;cin>>n>>k;
    VI v(N); //0 is right, 1 is left
    VI suf(N*N), rw, m;
    VI ans;
    queue<int> q1,q2;
    rep(i,0,n){
        char c;cin>>c;v[i]=c=='L';
    }
    int cnt=0;
    rep(i,0,n-1){
        if (v[i]==0 && v[i+1]==1){
            cnt++;
            if (q1.empty() || q1.front() !=i-1) q1.push(i-1);
            q1.push(i+1);
            v[i]=1;v[i+1]=0;
            ans.pb(i);
            i++;
        }
    }
    rw.pb(cnt);
    cnt=0;
    while(!q1.empty()){
        int l=q1.front(),r=l+1;
        q1.pop();
        if (l>=0 && r<n && v[l]==0 && v[r]==1){
            cnt++;
            if (q2.empty() || q2.front() != l-1) q2.push(l-1);
            q2.push(r);
            v[l]=1;v[r]=0;
            ans.pb(l);
            while (!q1.empty() && q1.front()==r)q1.pop();
        }
        if (q1.empty() && !q2.empty()){
            rw.pb(cnt);cnt=0;
            swap(q1,q2);
        }
    }
    int l=SZ(rw);
    per(i,0,l){
        suf[i]=suf[i+1]+rw[i];
    }
    //rep(i,0,l)cout<<suf[i]<<' ';
    //cout<<nl;
    //rep(i,0,SZ(ans))cout<<ans[i]<<' ';
    //cout<<nl;
    //DEBUG(l),DEBUG(k);
    if (k<l || suf[0]<k){
        cout<<-1<<nl;return 0;
    }
    rep(i,0,l){
        int diff=suf[i]-k;
        int t=max(1,rw[i]-diff);
        m.pb(t);k-=t;
    }
    assert(k==0);
    int p=0;
    rep(i,0,l){
        rep(j,0,m[i]-1){
            cout<<1<<' '<<ans[p++]+1<<nl;
        }
        int t=rw[i]-m[i]+1;
        assert(t<=n/2);
        cout<<t<<' ';
        rep(j,0,t){
            cout<<ans[p++]+1<<' ';
        }
        cout<<nl;
    }
}