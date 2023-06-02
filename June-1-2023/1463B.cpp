/*
Author: atharvd
Date:
Problem:
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

#define add(m, e) if(m.find(e) == m.end()) m[e] = 0; m[e]++;

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
    vi a1(n);
    vi a2(n);
    ll S = 0;
    for(int i = 0; i < n; i++){
        S += arr[i];
        if(i % 2 == 0){
            a1[i] = 1;
            a2[i] = arr[i];
        }
        else{
            a1[i] = arr[i];
            a2[i] = 1;
        }
    }
    ll s = 0;
    for(int i = 0; i < n; i++){
        s += abs(a1[i] - arr[i]);
    }
    if(s * 2 > S){
        aout(a2);
    }
    else{
        aout(a1);
    }
}

int main(int argc,char *argv[]){
#ifdef LOCAL_JUDGE
	freopen(argc > 1 ? argv[1] : "in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
 
	int t = 1;
	cin >> t;
	for(int i=1;i<=t;i++) {
		dout("***",i);
		solve();
	}
}
