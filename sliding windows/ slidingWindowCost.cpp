#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>, // comparison (can use less_equal<T> for multiset-like)
    rb_tree_tag,
    tree_order_statistics_node_update>;

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

struct MedianContainer {
    int sumLeft, sumRight;
    multiset<int> left,right;

    MedianContainer() {
        sumLeft = 0;
        sumRight = 0;
    }

    void adjust() {
      if (left.size() && right.size() && *left.rbegin()>*right.begin()) {
          int leftLast=*left.rbegin();
          int rightFirst=*right.begin();
          sumLeft+=rightFirst;
          sumLeft-=leftLast;
          sumRight-=rightFirst;
          sumRight+=leftLast;
          right.extract(rightFirst);
          left.insert(rightFirst);
          right.insert(leftLast);
          left.extract(leftLast);
      }
        if (left.size()>right.size()+1) {
            int leftLast=*left.rbegin();
            sumRight+=leftLast;
            sumLeft-=leftLast;
            left.extract(leftLast);
            right.insert(leftLast);
        }
        else if (left.size()<right.size()) {
            int rightFirst=*right.begin();
            sumLeft+=rightFirst;
            sumRight-=rightFirst;
            right.extract(rightFirst);
            left.insert(rightFirst);
        }
    }


    void insert(int val) {
        right.insert(val);
        sumRight+=val;
        adjust();
    }

    void remove(int val) {
        if (right.count(val)) {
            sumRight-=val;
            right.extract(val);
        }
        else {
            sumLeft-=val;
            left.extract(val);
        }
        adjust();
    }
    int cost() {
        int num1=(left.size()*1ll*(*left.rbegin()))-sumLeft;
        int num2=sumRight-(right.size()*1ll*(*left.rbegin()));
        return num1+num2;
    }
};


void solve() {
    // Solution logic here
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin>>nums[i];
    }

    MedianContainer container;

    for (int i=0;i<k;i++) {
        container.insert(nums[i]);
    }

    cout<<container.cost()<<" ";

    for (int i=k;i<n;i++) {
        container.remove(nums[i-k]);
        container.insert(nums[i]);
        cout<<container.cost()<<" ";
    }
    cout<<endl;
}

signed main() {
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