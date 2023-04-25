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
    int N; cin >> N;
    vector<int> P_one(N+1), P_two(N+1);
    P_one[0] = 0; P_two[0] = 0;
    rep(i, 1, N+1) {
        int C, P; cin >> C >> P;
        if (C == 1) {
            P_one[i] = P_one[i-1] + P;
            P_two[i] = P_two[i-1];
        }
        if (C == 2) {
            P_two[i] = P_two[i-1] + P;
            P_one[i] = P_one[i-1];
        }
    }

    int Q; cin >> Q;
    rep(i, 0, Q) {
        int L, R; cin >> L >> R;
        cout << P_one[R]-P_one[L-1] << " " << P_two[R]-P_two[L-1] << endl;
    }
    return 0;
}