#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int color[33]={};

vector<int> num[1001]={};
vector<int> st;
vector<int> st2;
int n,t=0,d=0,f=0;

void add_factor(int n){
	if (num[n].size()>0)
		return;
	for (int i=1;i<33;i++){
		if (n%i==0)
			num[n].pb(i);
	}
}

void recur(int k=0){
	if (d) return;
	if (k==n){
		if (t>11)
			return;
		d=1;
		cout << t << '\n';
		int f=1;
		for (int i : st2){
			cout << i << " ";
		}
		cout << '\n';
		return;
	}
	int d2=0;
	for (int i : num[st[k]]){
		if (color[i]>0&&i!=1){
			d2=1;
			st2[k]=color[i];
			break;
		}
	}
	if(d2){
		recur(k+1);
		st2[k]=0;
		return;
	}
	for (int i:num[st[k]]){
		if (i==1 && f)continue;
		color[i]=++t;
		st2[k]=color[i];
		if (i==1) f=1;
		recur(k+1);
		st2[k]=0;
		t--;
		color[i]=0;
		if(i==1) f=0;
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int zz;cin>>zz;
	int input;
	while(zz--){
		cin>>n;
		d=0;
		t=0;
		st2.clear();
		st.clear();
		for (int i=0;i<n;i++){
			cin>>input;
			st.pb(input);
			st2.pb(0);
			add_factor(input);
		}
		recur(0);
		//int c=0;
		/*
		for (int i : st){
			for (int j : num[i]){
				if (color[j]){
					cout << color[j] << " ";
					break;
				}
			}
		}
		*/
	}
}