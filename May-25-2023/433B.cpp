/*
Author: atharvd
Date: May/25/2023
Problem: 433B
*/

#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
#include<cmath>

using namespace std;

#define ain(a) for(int i=0;i<a.size();i++) cin >> a[i]
#define aout(a) for(int i=0;i<a.size();i++) { if(i > 0) cout << " "; cout << a[i]; }; cout << endl
#define couty cout << "YES\n"
#define coutn cout << "NO\n";

#define pb push_back
#define eb emplace_back
#define all(a) a.begin(),a.end()

#define nl cout << endl

#ifdef LOCAL_JUDGE
#include "local.hpp"
#else
template <typename Head, typename... Tail> void dout(Head&& h, Tail&&... t) {}
#endif

typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,int> pli; typedef tuple<ll,int,int> tllii;
typedef vector<int> vi; typedef vector<bool> vb; typedef vector<ll> vll; typedef vector<vector<int> > vvi;

ll inf = 1e18 + 1;

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    ain(arr);
    vi pref(n + 1);
    pref[0] = 0;
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + arr[i];
    }
    sort(all(arr));
    vi spref(n + 1);
    spref[0] = 0;
    for(int i = 0; i < n; i++){
        spref[i + 1] = spref[i] + arr[i];
    }
    dout(pref, spref);
    int q;
    int m;
    cin >> m;
    while(m--){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1) cout << pref[r] - pref[l - 1] << endl;
        else cout << spref[r] - spref[l - 1] << endl;
    }
}

int main(int argc,char *argv[]){
#ifdef LOCAL_JUDGE
	freopen(argc > 1 ? argv[1] : "in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
 
	int t = 1;
	//cin >> t;
	for(int i=1;i<=t;i++) {
		dout("***",i);
		solve();
	}
}
