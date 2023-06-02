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
    map<int, int> dp;
    int maxi = -1;
    for(auto a: arr){
        if(dp.find(a - 1) != dp.end()){
            dp[a] = dp[a - 1] + 1;
        }
        else{
            dp[a] = 1;
        }
        maxi = max(dp[a], maxi);
    }
    cout << maxi << endl;
    for(auto [a, b]: dp){
        vi ans;
        if(b == maxi){
            int num = a;
            for(int i = n - 1; i >= 0; i--){
                if(arr[i] == num){
                    ans.pb(i + 1);
                    num--;
                }
            }
            reverse(all(ans));
            aout(ans);
            break;
        }
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
