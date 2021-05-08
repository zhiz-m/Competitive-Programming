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

const int N=1010;
VI v(N,-1);
int n,k,mx;

int query(int a, int b){ //1 based index
    cout<<"? "<<b-a+1<<' ';
    rep(i,a,b+1)cout<<i<<' ';
    cout<<endl;
    int p;cin>>p;
    return p;
}

int search(int l, int r){
    if (l==r)return l;
    int cur = query(l,(l+r)/2);
    if (cur==mx) {
        //if (l==r)return l;
        return search(l,(l+r)/2);
    }
    else return search((l+r)/2+1,r);
}

void solve(){
    cin>>n>>k;
    rep(i,1,n+1)v[i]=-1;
    rep(i,1,k+1){
        int j;cin>>j;
        while(j--){
            int a;cin>>a;
            v[a]=i;
        }
    }
    mx=query(1,n);
    int p = search(1,n);
    int s=v[p];
    //DEBUG(s);
    int oth;
    int cnt=0;
    rep(i,1,n+1){
        if (v[i]!=s)cnt++;
    }
    cout<<"? "<<cnt<<' ';
    rep(i,1,n+1){
        if (v[i]!=s)cout<<i<<' ';
    }
    cout<<endl;
    cin>>oth;
    //DEBUG(suc);
    if (s==-1 || oth==mx){
        cout<<"! ";
        rep(i,1,k+1)cout<<mx<<' ';
    }else{
        
        cout<<"! ";
        rep(i,1,k+1)cout<<(i==s?oth:mx)<<' ';
    }
    cout<<endl;
    string str;cin>>str;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--)solve();
}