
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

vector<int> arr={1,1,1,2,3};
int maxEl=1;
bool testing=true;
int interactor(int x) {
    if (x==maxEl) return 1;
    return 0;
}
int ask(int x) {
    cout<<"? "<<x<<endl;
    if (testing) {
        return interactor(x);
    }
    int res; cin>>res ;return res;
}

void solve() {
    // Solution logic here

    int min=1;
    int max=1e9;

    //initialize a random number generator
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> dis(min, max); //uniform distribution

    // int random_value=dis(gen);

    for(int i=1;i<=500;i++) {
        int randomIdx=dis(gen);
        int res=ask(randomIdx);
        if (res==1) {
            cout<<"! "<<randomIdx<<endl;
            break;
        }
    }
}

signed main() {
    FAST_IO;

    int t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}