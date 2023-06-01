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
    int n, k;
    cin >> n >> k;
    vi arr(n);
    ain(arr);
    vi w(k);
    ain(w);
    sort(all(arr));
    sort(all(w));
    reverse(all(w));
    ll ans = 0;
    int l = 0;
    int r = n - 1;
    for(int i = k - 1; i >= 0; i--){
        if(w[i] != 1){
            break;
        }
        ans += 2 * arr[r];
        r--;
    }
    for(int i = 0; i < k; i++){
        if(w[i] == 1) break;
        //cout << arr[l] << " " << arr[r] << endl;
        ans += arr[l] + arr[r];
        l += w[i] - 1;
        r--;
    }
    cout << ans << endl;
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
