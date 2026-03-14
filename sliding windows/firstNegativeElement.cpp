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



void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void firstNegativeElement(vector<int> v,int k,int n) {
    queue<int> q;
    vector<int> arr;

    for (int i = 0; i < k; i++) {
        if (v[i]<0) {
            q.push(i);
        }
    }

    cout<<1<<" :  " <<endl;
    printQueue(q);
    if (q.size()) {
        arr.push_back(q.front()+1);
    }
    else {
        arr.push_back(-1);
    }

    for (int i = k; i < n; i++) {
        //remove elements at front that are not part of sliding window
        if (q.front()==i-k) {
            cout<<"element popped "<<endl;
            q.pop();
        }
        if (v[i]<0) {
            q.push(i);
        }
        cout<<i-k+2<<" : "<<endl;
        printQueue(q);
        if (q.size()) {
            arr.push_back(q.front()+1);
        }
        else {
            arr.push_back(-1);
        }

    }

    for (int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve() {
    // Solution logic here
    vector<int> v={1,1,2,-1,3,2,-3,-4,2};
    int k=3;
    firstNegativeElement(v,k,v.size());
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