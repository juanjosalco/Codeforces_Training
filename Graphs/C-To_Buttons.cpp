#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <cmath>
#include <queue>
 
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

//g++-12 -std=c++17 twoButtons.cpp && ./a.out < input.txt > output.txt

lli n, m;

void bfs(){
    vi visitados(2e5, 0);
    queue<int> bfs;
    bfs.push(n);
    while(!bfs.empty()){
        int nodoActual = bfs.front();
        bfs.pop();
        if(nodoActual == m){
            cout << visitados[nodoActual] << endl;
            return;
        }
        if(nodoActual * 2 <= 2e5 && visitados[nodoActual * 2] == 0){
            visitados[nodoActual * 2] = visitados[nodoActual] + 1;
            bfs.push(nodoActual * 2);
        }
        if(nodoActual > 0 && visitados[nodoActual - 1] == 0){
            visitados[nodoActual - 1] = visitados[nodoActual] + 1;
            bfs.push(nodoActual - 1);
        }
    }
}

int main() { _
    cin >> n >> m;
    bfs();
}