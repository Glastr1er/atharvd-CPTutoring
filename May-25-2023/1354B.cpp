/*
Author: atharvd
Date: May/25/2023
Problem: 1354B
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
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    int r = 0;
    vi freq(3);
    freq[s[0] - '1']++;
    int ans = 1e9;
    while(l < n - 1){
        if(freq[0] * freq[1] * freq[2] == 0 && r < n - 1){
            r++;
            freq[s[r] - '1']++;
        }
        if(freq[0] * freq[1] * freq[2] != 0){
            ans = min(ans, r - l + 1);
            freq[s[l] - '1']--;
            l++;
        }
        else if(r == n - 1){
            l++;
        }
    }
    cout << ((ans == 1e9) ? 0 : ans) << endl;
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
