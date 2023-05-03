#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define PI 3.1415926535897932384626433832795028841971
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const long long INF = (1LL << 60);
const int ddx[4] = {1, 0, -1, 0};
const int ddy[4] = {0, 1, 0, -1};

template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }


template <class T>
void printVector(const vector<T>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}


int main() {
    ll a, b, c; cin >> a >> b >> c;
    // 問題文通りに解く
    // if (log2(a) < b*log2(c)) cout << "Yes" << endl;
    // else cout << "No" << endl;
    // logの計算では値が省略されて返される可能性があるため工夫する
    // log2(a) < b*log2(c) -> a < c^bに置き換える．
    // pow(c, b)を使うとこれも省略される可能性があるので，repで回す
    ll b_c = c;
    rep(i, 0, b-1) b_c *= c;
    if (a < b_c) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
