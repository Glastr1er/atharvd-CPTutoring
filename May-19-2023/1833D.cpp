/*
Author: atharvd
Date: May/19/2023
Problem: 1833D
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
    vi maxi;
    maxi.pb(arr[n - 1]);
    for(int i = 0; i < n - 1; i++){
        maxi.pb(arr[i]);
    }
    int r = -1;
    if(arr[0] == n){
        for(int i = 0; i < n - 1; i++){
            if(arr[i + 1] == n - 1) r = i;
        }
    }
    else{
        for(int i = 0; i < n - 1; i++){
            if(arr[i + 1] == n) r = i;
        }
    }
    for(int l = 0; l <= r; l++){
        vi newPermi;
        //cout << l << " " << r << endl;
        for(int i = r + 1; i < n; i++){
            newPermi.pb(arr[i]);
        }
        for(int i = l; i <= r; i++){
            newPermi.pb(arr[r - (i - l)]);
        }
        for(int i = 0; i < l; i++){
            newPermi.pb(arr[i]);
        }
        maxi = max(maxi, newPermi);
    }
    aout(maxi);
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
