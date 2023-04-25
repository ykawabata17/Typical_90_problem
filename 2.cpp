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
    int N; cin >> N; // 入力受け取り(N個の括弧の組み合わせを探す)
    if (N%2 == 1) return 0; // Nが奇数の場合、条件を満たす組み合わせは存在しない

    // 2^Nから順次ビット列を生成する
    for (int bit = (1<<N); bit >= 0; --bit) { 
        string bs = bitset<20>(bit).to_string(); // bitを2進数表現に変換する
        bs = bs.substr(20-N, N); // 余分な桁数を削る
        int cnt_one = count(bs.begin(), bs.end(), '1'); // 桁数ごとに1と0の個数を数える
        int cnt_zero = count(bs.begin(), bs.end(), '0');
        if (cnt_one != cnt_zero) continue; // 1と0の個数が一致しなければスキップする

        int num = 0;
        bool flag = true;
        rep(i, 0, N) {
            if (bs[i] == '1') num+=1; // '(' が出現したらnum を+1する
            else num-=1; // ')' が出現したらnum を-1する
            if (num < 0) flag = false; // ')' の個数が'('より大きくなった場合、flag をfalseにする
        }
        if (flag) { // flagがtrueの場合、条件を満たす組み合わせとして出力する
            rep(i, 0, N) {
                if (bs[i] == '1') cout << '('; // bs[i]が'1'ならば"("を表示する
                else cout << ')'; // bs[i]が'0'ならば")"を表示する
            }
            cout << endl;
        }
    }
    return 0;
}