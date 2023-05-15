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

vi dp;
string a;

vector<bool> computado;

lli answer(lli x){
    if(x == 0) return dp[x];
}

lli fibo(lli x){
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(computado[x]) return dp[x];
    dp[x] = fibo(x - 2) + fibo(x - 1);
    computado[x] = true;
    return dp[x];
}

int main() { _
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a;
    dp.resize(1e3);
    computado.assign(1e3, false);

    answer(a.size()-1);
    lli max = 0;
    for(auto num : dp){
        if(num > max) max = num;
        cout << num << endl;
    }

    cout << max;

}