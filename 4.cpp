#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define PI 3.1415926535897932384626433832795028841971
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
    int H, W; cin >> H >> W;
    vector<vector<int>> A(H), B(H);
    rep(i, 0, H) rep(j, 0, W) {
        int x; cin >> x;
        A[i].push_back(x); // 元の行列Aの要素を入力
    }

    // 行列Bを求める
    rep(i, 0, H) {
        int sum = 0;
        rep(j, 0, W) {
            sum += A[i][j];
        }
        rep(j, 0, W) {
            B[i].push_back(sum); // 行ごとの和を順番に格納していく
        }
    }
    rep(i, 0, W) {
        int sum = 0;
        rep(j, 0, H) {
            sum += A[j][i];
        }
        rep(j, 0, H) {
            B[j][i] += sum; // 列ごとの和を順次たすことで、最終的な行列Bの各要素を求める
        }
    }

    // 出力
    rep(i, 0, H) {
        rep(j, 0, W) {
            cout << B[i][j]-A[i][j]; // 各要素の値を出力する際に、元の行列Aの要素を引く
            if (j != W-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
