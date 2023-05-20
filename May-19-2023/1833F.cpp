/*
Author: atharvd
Date: May/19/2023
Problem: 1833F
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

ll mpow(ll b, ll ex, ll mod){
	if (b==1) return 1;
	ll r = 1;
	while (ex ){
		if (ex&1)r=(r * b)%mod;
		ex = ex >> 1;
		b = (b * b)%mod;
	}
	return r;
}
 
ll invmod(ll n,ll MOD) { return mpow(n,MOD-2,MOD); }

void solve() {
    int n, m;
    cin >> n >> m;
    vi arr(n);
    ain(arr);
    sort(all(arr));
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        if(freq.find(arr[i]) == freq.end()){
            freq[arr[i]] = 0;
        }
        freq[arr[i]]++;
    }
    vi dist;
    for(auto [a, b]: freq) dist.pb(a);
    if(dist.size() < m){
        cout << 0 << endl;
        return;
    }
    int l = 0;
    int r = m - 1;
    ll MOD = 1000000007;
    ll count = 0;
    ll ans = 1;
    for(int i = l; i <= r; i++){
        ans *= freq[dist[i]];
        ans %= MOD;
    }
    //scout << ans << endl;
    while(r < dist.size()){
        if(dist[r] - dist[l] < m){
            count += ans;
            count %= MOD;
        }
        ans = (ans * invmod(freq[dist[l]], MOD)) % MOD;
        l++;
        r++;
        ans *= freq[dist[r]];
        ans %= MOD;
    }
    cout << count << endl;
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
