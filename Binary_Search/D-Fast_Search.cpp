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
    int n, k;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> k;
    for(int i = 0; i < k; i++){
        int leftBoundary, rightBoundary;
        cin >> leftBoundary >> rightBoundary;
        int l = -1;
        int r = n; 
        while(r > l + 1){
            int m = (l + r) / 2;
            if(a[m] < leftBoundary){
                l = m;
            } else{
                r = m;
            }
        }
        int left = r + 1;
        l = -1;
        r = n;
        while(r > l + 1){
            int m = (l + r) / 2;
            if(a[m] <= rightBoundary){
                l = m;
            } else{
                r = m;
            }
        }
        int right = l + 1;

        cout << (right - left + 1) << " ";
    }
}