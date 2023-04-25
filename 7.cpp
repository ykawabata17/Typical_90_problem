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
    int N; cin >> N;
    vector<ll> A;
    rep(i, 0, N) {
        ll a; cin >> a;
        A.push_back(a);
    }
    int Q; cin >> Q;
    vector<ll> B;
    rep(i, 0, Q) {
        ll b; cin >> b;
        B.push_back(b);
    }
    // 入力受け取り終了

    sort(A.begin(), A.end()); // A を昇順にソートする

    rep(i, 0, Q) {
        auto iter = lower_bound(A.begin(), A.end(), B[i]); // vector A の中で、値が B[i] 以上となる最小の要素へのイテレーターを取得
        int idx = iter - A.begin(); // 取得したイテレーターから、インデックスを計算する
        if (idx == 0) {
            cout << abs(A[0]-B[i]) << endl; // B[i]がA[0]よりも小さい場合は、A[0]とB[i]の差を出力
        }
        else {
            int score = min(abs(A[idx-1]-B[i]), abs(A[idx]-B[i])); // A[idx-1]とB[i]の差と、A[idx]とB[i]の差をとって、小さいほうをscoreとして代入する
            cout << score << endl; // scoreを出力する
        }
    }
    return 0;
}
