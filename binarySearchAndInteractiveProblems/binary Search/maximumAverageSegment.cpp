
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const ll MOD = 1e9 + 7;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

ll expo(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_mul(ll a, ll b, ll m) { return (a % m * b % m) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((a - b) % m + m) % m; }
ll mod_div(ll a, ll b, ll m) { return mod_mul(a, mminvprime(b, m), m); }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }


pair<int, int> anySubArrWithPositiveSum(vector<lld> &arr, int d, int n) {
    vector<lld> pre(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }
    lld ans = -1e18;
    lld minSoFar=0;
    int bestIndexSoFar=-1;
    for (int right = d-1; right < n; right++) {
        lld bestSubarrEndingHere=pre[right]-minSoFar;
        ans=max(ans, bestSubarrEndingHere);
        if (ans>=0) {
            return make_pair(bestIndexSoFar+1,right);
        }
        if (minSoFar > pre[right-d+1]) {
            minSoFar=pre[right-d+1];
            bestIndexSoFar=right-d+1;
        }


    }

    return {-10,-10};

}

pair<int,int> bestSubarr(long double x,vector<int> &v,int d,int n) {
    vector<lld> transformedArr(n);
    for (int i = 0; i < n; i++) {
        transformedArr[i] = v[i] - x;
    }

    return anySubArrWithPositiveSum(transformedArr,d,n);
}
lld maximumSum(vector<lld> &arr, int d, int n) {
    vector<lld> pre(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }
    lld ans = -1e18;
    lld minSoFar=0;
    for (int right = d-1; right < n; right++) {
        lld bestSubarrEndingHere=pre[right]-minSoFar;
        ans=max(ans, bestSubarrEndingHere);
        if (minSoFar > pre[right-d+1]) {
            minSoFar=pre[right-d+1];
        }
    }
    return ans;
}

bool possible(lld mid, vector<int> &v, int d, int n) {
    vector<lld> transformedArr(n);
    for (int i = 0; i < n; i++) {
        transformedArr[i] = v[i] - mid;
    }

    return maximumSum(transformedArr,d,n)>=0;
}

void solve() {
    // Solution logic here
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (auto &num: v) {
        cin >> num;
    }

    lld low = 0;
    lld high = 100;
    int iterations = 100;
    // yyyyyyyyyyyynnnnnnnnnnnnnnnnn
    // mean >=x
    for (int i = 0; i < iterations; i++) {
        lld mid = low + (high - low) / 2;
        if (possible(mid, v, d,n)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << setprecision(10) << fixed;
    pair<int,int> ans=bestSubarr(low,v,d,n);
    cout << ans.first+1 << " " << ans.second+1 << endl;
}

signed main() {
    FAST_IO;



    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
