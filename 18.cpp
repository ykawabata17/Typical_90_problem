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
    int T; cin >> T;
    int L, X, Y; cin >> L >> X >> Y;
    int Z = 0;
    int Q; cin >> Q;
    rep(i, 0, Q) {
        int E; cin >> E;
        // 原点から観覧車に乗っている人の角度を求める(0 ≤ theta < 2pi)
        double t_man = 360*E / T;
        // 円の公式とtanから観覧車に乗っている人の座標を求める
        double y = -(L/2)*sin(t_man);
        double z = -(L/2)*cos(t_man) + (L/2);
        double x = 0;
        // 観覧車と像の水平距離を求める
        double dist = sqrt(X*X + pow(y-Y, 2));
        // 俯角を求める
        double theta = atan2(z, dist)*(180/PI);
        cout << fixed << setprecision(10) << theta << endl;
    }
    return 0;
}