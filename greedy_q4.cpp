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

typedef struct t tree;

struct t{
    char val=' ';
    int num;
    tree *left=NULL, *right=NULL; 
};

int nums[] = {82,15,28,43,127,22,20,61,70,2};
int p=0;
map<int, tree*> m;

void out(tree *cur){
    if (cur==NULL)return;
    printf("[");
    printf("\n%c",cur->val);
    if (cur->val!=' ')printf("(%d)",cur->num);
    out(cur->left);
    out(cur->right);
    printf("]");
    free(cur);
}

int main(){
    
    rep(i,'a','j'+1){
        tree *cur=(tree*)malloc(sizeof(struct t));
        cur->left = cur->right = NULL;
        cur->val=i;
        int temp = nums[p++];
        cur->num=temp;
        m[temp]=cur;
    }
    while(SZ(m)>1){
        int tot=0;
        tree *cur=(tree*)malloc(sizeof(struct t));
        cur->val=' ';
        auto s1=m.begin();
        tot+=s1->fi;
        cur->left = s1->se;
        m.erase(s1);
        s1=m.begin();
        tot+=s1->fi;
        cur->right = s1->se;
        m.erase(s1);
        m[tot]=cur;
        cur->num=tot;
    }
    out(m.begin()->se);
}