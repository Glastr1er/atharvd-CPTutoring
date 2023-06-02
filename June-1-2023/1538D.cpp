/*
Author: atharvd
Date: 6/1/2023
Problem: 1538D.cpp
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

vi primes;
vb compMap(100001);

void generatePrimes(){
    for(ll i = 2; i < 100001; i++){
        if(!compMap[i]){
            primes.pb(i);
            for(ll j = i * i; j < 100001; j += i){
                compMap[j] = true;
            }
        }
    }
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if(k == 1){
        if(a == b){
            cout << "NO\n";
            return;
        }
        if(a % b == 0 || b % a == 0){
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    int ad = 0;
    int bd = 0;
    for(auto p: primes){
        while(a % p == 0){
            a /= p;
            ad++;
        }
        while(b % p == 0){
            b /= p;
            bd++;
        }
    }
    if(a > 1) ad++;
    if(b > 1) bd++;
    if(ad + bd >= k){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(int argc,char *argv[]){
#ifdef LOCAL_JUDGE
	freopen(argc > 1 ? argv[1] : "in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    generatePrimes();
	int t = 1;
	cin >> t;
	for(int i=1;i<=t;i++) {
		dout("***",i);
		solve();
	}
}
