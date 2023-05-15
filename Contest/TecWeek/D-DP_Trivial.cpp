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

    lli n, s;
    cin >> n >> s;
    lli cont = 0;
    vi a(n);
    for(lli i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    lli mid = ceil(n / 2);
    if(a[mid] < s){
        for(lli i = n-1; i >= mid; i--){
            while(a[i] < s){
                a[i]++;
                cont++;
            }
        }
    } else{
        for(lli i = mid; i >= 0; i--){
            while(a[i] > s ){
                a[i]--;
                cont++;
            }
        }
    }

    cout << cont;
}
    