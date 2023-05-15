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

int main() { _
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    lli n;
    cin >> n;
    vector<vi> happiness(n+1, vector<lli>(n+1));
    for(int i = 0; i < n; i++){
        cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
    }
    for(int i = 1; i < happiness.size(); i++){
        happiness[i][0] += max(happiness[i-1][1], happiness[i-1][2]);
        happiness[i][1] += max(happiness[i-1][0], happiness[i-1][2]);
        happiness[i][2] += max(happiness[i-1][0], happiness[i-1][1]);
    }
    lli maximum = 0;
    
     for (int i = 0; i < happiness.size(); i++) {
        for (int j = 0; j < happiness[i].size(); j++) {
            if (happiness[i][j] > maximum) {
                maximum = happiness[i][j];
            }
        }
    }
    cout << maximum << endl;
}