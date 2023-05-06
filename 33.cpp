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
    int H, W; cin >> H >> W;
    // コーナーケースを先に記載
    if (H == 1 || W == 1) {
        cout << H*W << endl;
        return 0;
    }
    int ans;
    int w, h;
    w = (W + 2 - 1) / 2;     // W / 2を切り上げで計算
    h = (H + 2 - 1) / 2;     // H / 2を切り上げで計算
    ans = w * h;
    cout << ans << endl;
    return 0;
}
