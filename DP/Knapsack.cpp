#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
 
using namespace std;
 
typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;
 
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
 
///-------------------------------------------------------------------------
///-------------------------------------------------------------------------
 
const lli MOD = 1e9 + 7;
 
///-------------------------------------------------------------------------
 
lli mcd(lli a, lli b) {return b ? mcd (b, a % b) : a;}
lli mcm(lli a, lli b) {return (!a || !b) ? 0 : a * b / mcd(a, b);}

//g++-12 -std=c++17 main.cpp && ./a.out < input.txt > output.txt

vector<pii> a;
lli dp[109][100009];
lli n, k;

lli knapsack(lli x, lli w){
    if(x == n) return 0;
    if(dp[x][w] != -1) return dp[x][w];
    lli ans = knapsack(x + 1, w);
    if(w + a[x].first <= k){
        ans = max(ans , knapsack(x + 1, w + a[x].first) + a[x].second);
    }
    return dp[x][w] = ans;
}

int main() { _
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n >> k;
    a.resize(n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

   cout <<  knapsack(0, 0);
}