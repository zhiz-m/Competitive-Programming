#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
bool query(int a, int b){
    return v[a] == v[b];
}

pair<int,int> solve(int n){
    vector<int> cur;
    for(int i=0; i<n; i++)cur.push_back(i);
    while(1){
        vector<int> next_cur;
        for(int i=1; i<(int)cur.size(); i+=2){
            int a=cur[i-1], b=cur[i];
            if (query(a,b)){
                next_cur.push_back(a);
            }
        }
        if (next_cur.size()==0){
            if (cur.size()%2) return make_pair(cur.front(),cur.front());
            return make_pair(cur[0], cur[1]);
        }
        cur=next_cur;
    }
}

int main(){
    int n;cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)cin>>v[i];
    pair<int,int> ret = solve(n);
    int a=ret.first, b=ret.second;
    for (int i=0; i<2; i++){
        if (a==-1) continue;
        int cnt=0;
        for(int j=0; j<n; j++)cnt+=query(a,j);
        if (cnt>=n/2){
            cout<<a<<'\n';
            return 0;
        }
        swap(a,b);
    }
    cout<<-1<<'\n';
}