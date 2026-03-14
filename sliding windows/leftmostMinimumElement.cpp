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

void print(deque<int> dq,vector<int> arr) {
    while (!dq.empty()) {

        cout <<  arr[dq.front()] << ","<<dq.front()+1<<"        ";
        dq.pop_front();
    }
    cout << endl;
}

void leftmostMinimumElement(vector<int> v,int k,int n) {
    deque<int> dq;
    vector<int> arr;

    //inserting the first k elements
    for(int i=0;i<k;i++) {
        while (!dq.empty() && v[dq.back()]>v[i]) {
            dq.pop_back();
        }
        cout<<i+1<<endl;
        //the deque after each ith element of array is pushed back
        dq.push_back(i);
        print(dq,v);
    }
    //actual answer starts from here
    arr.push_back(dq.front()+1);

    for(int i=k;i<n;i++) {
        while (!dq.empty() && v[dq.back()]>v[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (dq.front()==i-k) {//now this element at this index is smaller than v[i] but  the subarray that will be formed by including this element is greater than k
            dq.pop_front();
        }

        cout<<i+1<<endl;

        arr.push_back(dq.front()+1);
        print(dq,v);
    }


    for (int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void solve() {
    // Solution logic here
    vector<int> v = {1, 3, 1, 2, 4, 5, 1, 7, 2};
    int k = 3;
    leftmostMinimumElement(v, k, v.size());
}

int main() {
    FAST_IO;

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("Error.txt", "w", stderr);
// #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}