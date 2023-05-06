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
    N += 1;
    vector<int> num;
    rep(i, 1, N) num.push_back(i);
    vector<vector<int>> A(N);
    rep(i, 1, N) {
        rep(j, 1, N) {
            int a; cin >> a;
            A[i].push_back(a);
        }
    }
    int M; cin >> M;
    vector<pair<int, int>> XY(M);
    rep(i, 0, M) {
        int x, y; cin >> ++x >> ++y;
        XY[i].first = x;
        XY[i].second = y;
    }
    //　入力受け取り完了

    int ans = 100000000;
    // 順列全探索開始
    do
    {
        // 仲が悪い選手が隣にいる場合は却下
        bool flag = true;
        rep(i, 0, M) {
            rep(j, 0, N-2) {
                if (num[j] == XY[i].first && num[j+1] == XY[i].second) flag = false;
                if (num[j] == XY[i].second && num[j+1] == XY[i].first) flag = false;
            }
        }
        // 順番にかかる時間を足し合わせて一番短いタイムを更新していく
        if (flag) {
            int i = 0;
            int s = 0;
            for(auto n : num) {
                s += A[n][i];
                i++;
            }
            ans = min(ans, s);
        }
    } while (next_permutation(num.begin(), num.end()));
    if (ans == 100000000) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
