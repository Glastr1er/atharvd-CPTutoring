/*
Author: atharvd
Date: May/20/2023
Problem: 1833G
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

vi ans;

int dfs(vector<map<int, int>> &edges, vvi &adj, int u, int p){
    int sum = 0;
    for(auto v: adj[u]){
        if(v == p) continue;
        int x = dfs(edges, adj, v, u);
        if(x == -1){
            return -1;
        }
        sum += x;
    }
    if(sum > 2){
        return -1;
    }
    if(sum == 2){
        ans.pb(edges[u][p]);
    }
    return (sum + 1) % 3;
}

void solve() {
    int n;
    cin >> n;
    vvi adj(n);
    ans.clear();
    vector<map<int, int>> edges(n);
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        edges[a][b] = i;
        edges[b][a] = i;
    }
    if(n % 3 != 0){
        cout << "-1\n";
        return;
    }
    if(dfs(edges, adj, 0, 0) == -1){
        cout << -1 << endl;
        return;
    }
    cout << ans.size() - 1 << endl;
    for(int i = 0; i < ans.size() - 1; i++) cout << ans[i] << " ";
    cout << endl;
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
