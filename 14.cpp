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
    ll N; cin >> N;
    vector<ll> X;
    rep(i, 0, 3) {
        ll x; cin >> x;
        X.push_back(x);
    }
    sort(X.begin(), X.end());
    ll ans = INF;
    rep(i, 0, 10000) { // X[0]の個数を 0 〜 10000まで探索
        rep(j, 0, 10000-i) { // X[1]の個数を 0 〜 10000-iまで探索
            ll sum = X[0]*i+X[1]*j; // X[0], X[1]の総和を計算
            if ((N-sum)%X[2] == 0) { // X[2]で割り切れる場合
                ans = min(ans, i+j+(N-sum)/X[2]); // 最小値を更新
            }
        }
    }
    cout << ans << endl; // 答えを出力
    return 0;
}
