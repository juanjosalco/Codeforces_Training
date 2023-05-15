#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <cmath>
 
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

lli n, m, k, q;
const lli INF = 4e18;
vi monedas;
const lli MAXN = 1e5;
lli dp[MAXN];

vector<bool> computed;

lli f(lli x){
    if(x == 0)return 0;
    if(!computed[x]) return dp[x];
    lli res = INF;
    fore(i, 0, n){
        if(x - monedas[i] >= 0){
            res = min(res, f(x - monedas[i])+1);
        }
    }
    dp[x] = res;
    return dp[x];
}

int main() { _
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    computed.assign(INF, false);
    cin >> n >> q;
    monedas.resize(n);
    fore(i, 0, n){
        cin >> monedas[i];
    }
    fore(i, 0, q){
        lli xd; 
        cin >> xd;
        cout << f(xd) << endl;
    }
}