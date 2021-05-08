#include <bits/stdc++.h>
#define pb push_back
#define DEBUG(x) cerr<< '<' << #x << ':' << x << endl

using namespace std;

int n,h,l,r;

bool good(int a){
	return l<=a && a<=r;
}

int ct(int a){
	while(a<0) a+=h;
	while (a>h-1) a-=h;
	return a;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vector<pair<int,int>> v1; // time, good_sleep_amount
	vector<pair<int,int>> v2;
	int a[2001];
	cin>>n>>h>>l>>r;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	v1.pb({0,0});
	for (int i=0;i<n;i++){
		for (int j=0;j<=i+1;j++){
			pair<int,int> t1,t2;
			if (j!=0) 
				t1 = v1[j-1];
			if (j!=i+1) 
				t2 = v1[j];
			if (j==0){
				int ti=ct(a[i]+t2.first);
				v2.pb({ti,t2.second+good(ti)});
			}
			else if (j==i+1){
				int ti=ct(a[i]+t1.first-1);
				v2.pb({ti,t1.second+good(ti)});
			}
			else{
				int ti=ct(a[i]+t2.first);
				//int z=ct(a[i]+t2.second)==ct(a[i]+t1.first-1);
				//int z1=t2.first;
				//int z2=ct(v1[i].first+t1.first-1);
				//DEBUG(z1);
				//DEBUG(z2);
				//int t2=ct(a[i]+t2.first);
				int g=good(ti);
				v2.pb({ti,max(t1.second,t2.second)+g});
			}
			//DEBUG(v2[j].first);
			//DEBUG(v2[j].second);
		}
		//cout<<'\n';
		swap(v2,v1);
		v2.clear();
	}
	int m=0;
	for (auto i:v1){
		m=max(i.second,m);
	}
	cout<<m<<'\n';
}