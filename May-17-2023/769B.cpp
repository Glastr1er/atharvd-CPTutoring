/*
Author: atharvd
Date: May/17/2023
Problem: 769B
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
    vector<pii> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    if(arr[0].first == 0){
        cout << -1 << endl;
        return;
    }
    sort(arr.rbegin(), --arr.rend());
    dout(arr);
    int canSend = 0;
    vector<pii> sending;
    vector<pii> ans;
    for(int i = 1; i < min(1 + arr[0].first, n); i++){
        ans.pb({1, arr[i].second});
        sending.pb(arr[i]);
        canSend += arr[i].first;
    }
    int bound = arr[0].first;
    int ps = -1;
    int s = 0;
    while(bound < n - 1){
        int temp = 0;
        vector<pii> tempSend;
        int x = 0;
        ps = ans.size();
        for(int i = bound + 1; i < min(bound + 1 + canSend, n); i++){
            sending[x].first--;
            tempSend.pb(arr[i]);
            ans.pb({sending[x].second, arr[i].second});
            if(sending[x].first == 0) x++;
            temp += arr[i].first;
        }
        bound += canSend;
        canSend = temp;
        sending = tempSend;
        s = ans.size();
        if(ps == s){
            cout << -1 << endl;
            return;
        }
    }
    cout << ans.size() << endl;
    for(auto [a, b]: ans){
        cout << a << " " << b << endl;
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
