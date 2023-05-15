#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <cmath>
#include <climits>
 
using namespace std;
 
typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;
typedef vector<bool> vb;
 
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

vi heights;
vb computed;
vi dp;

lli n;

lli frog1(lli x){
    if(x == 0) return 0;
    if(x == 1) return abs(heights[1] - heights[0]);
    if(computed[x]) return dp[x];
    dp[x] = dp[x+1] + min(abs(heights[x-1] - heights[x]), abs(heights[x-2] - heights[x])); 
    if(dp[x] == dp[x+1] + abs(heights[x-1] - heights[x])){
        computed[x] = true;
        frog1(x-1);

    } else if(dp[x] == dp[x+1] + abs(heights[x-2] - heights[x])){
        computed[x] = true;
        frog1(x-2);
    }
    return dp[x];
}


int main() { _
    
    //freopen("input.txt", "r", stdin
    //freopen("output.txt", "w", stdout);

    // ------- ITERATIVE SOLUTION ------- //

    // cin >> n;

    // heights.resize(n);
    // computed.assign(1e6, false);
    // dp.resize(1e6);

    // for(int i = 0; i < n; i++){
    //     cin >> heights[i];
    // }
    // dp[0] = 0;
    // dp[1] = abs(heights[1] - heights[0]);
    // for(int i = 2; i < n; i++){
    //     dp[i] = min(dp[i-1] + abs(heights[i] - heights[i-1]), dp[i-2] + abs(heights[i] - heights[i-2]));
    // }

    // cout << dp[n-1];

    // ------- RECURSIVE SOLUTION ------- //

    cin >> n;

    heights.resize(n);
    dp.assign(n, 0);
    computed.assign(n, false);

    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    cout << frog1(n-1);
}