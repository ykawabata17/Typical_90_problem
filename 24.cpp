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
    ll N, K; cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, 0, N) cin >> A.at(i);
    rep(i, 0, N) cin >> B.at(i);
    ll diff = 0;
    rep(i, 0, N) diff += abs(A[i]-B[i]);
    if ((diff-K) <= 0 && abs(K-diff)%2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
