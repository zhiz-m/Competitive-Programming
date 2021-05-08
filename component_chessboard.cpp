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

int b,w,shift,cb,cw;

void pr(int x,int y,int f){
    if (f==1)cout<<x<<' '<<y+1<<nl;
    else cout<<x<<' '<<y-1<<nl;
}

int main(){
    upgrade();
    int tc;cin>>tc;
    while(tc--){
        cin>>b>>w; // we start at coord 4,3
        cb=cw=shift=0; //downwards shift
        if (w+b==1){
            cout<<"YES"<<nl;
            if (w==1)cout<<4<<' '<<4<<nl;
            else cout<<3<<' '<<4<<nl;
            continue;
        }
        if (b>w){
            swap(b,w);
            shift++;
        }
        //DEBUG(b);
        if (w>3*b + 1){
            cout<<"NO"<<nl;
            continue;
        }
        //DEBUG(b);
        cout<<"YES"<<nl;
        int x=4,y=3+shift;
        cw+=b-1;
        while(cb<b){
            cout<<x<<' '<<y<<nl;
            cb++;
            if (cb<b)cout<<x+1<<' '<<y<<nl;
            x+=2;
        }
        //DEBUG(x);
        x=4;
        int ex=4+2*(b-1);
        while(cw<w && cw<3*b-1){
            int cnt=0;
            while(cnt<2 && cw<w){
                pr(x,y,cnt);cw++;cnt++;
            }
            x+=2;
        }
        //DEBUG(b);
        x=4;
        int f=0;
        while(cw<w){
            if (f) cout<<x-1<<' '<<y<<nl;
            else cout <<ex+1<<' '<<y<<nl;
            cw++;f++;
        }
        //DEBUG(b);
        assert(f<=2);
        assert(cw==w);
        assert(cb==b);
        //DEBUG(f);
    }
}