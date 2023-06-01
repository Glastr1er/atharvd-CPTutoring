/*
Author: atharvd
Date: May/30/2023
Problem: 1365C
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
    vi a(n);
    vi b(n);
    ain(a);
    for(auto &A: a) A--;
    ain(b);
    for(auto &B: b) B--;
    vi pos(n);
    for(int i = 0; i < n; i++){
        pos[b[i]] = i;
    }
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        int loc = pos[a[i]];
        int move;
        if(i == loc){
            move = 0;
        }
        if(i < loc){
            move = loc - i;
        }
        if(i > loc){
            move = n - i + loc;
        }
        if(freq.find(move) == freq.end()) freq[move] = 0;
        freq[move]++;
    }
    int maxi = 0;
    for(auto [a, b]: freq){
        maxi = max(maxi, b);
    }
    cout << maxi << endl;
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
