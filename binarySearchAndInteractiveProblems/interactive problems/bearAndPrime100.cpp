
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


vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

void solve() {
    // Solution logic here

 int count=0;
    for(int i=0;i<prime.size();i++) {
        cout<<prime[i]<<endl;
        string out;
        cin>>out;
        if (prime[i]==2 && out=="yes") {
            cout<<4<<endl;
            cin>>out;
            count++;
            if (out=="yes") {
                cout<<"composite"<<endl;
                return;
            }
        }
        else {
            if (out=="yes") {
                count++;
                if (i<=3) {
                    cout<<prime[i]*prime[i]<<endl;
                    cin>>out;
                    if (out=="yes") {
                        cout<<"composite"<<endl;
                        return;
                    }
                }
            }
        }
    }

    if (count>1) {
        cout<<"composite"<<endl;
    }
    else {
        cout<<"prime"<<endl;
    }
}

signed main() {
    FAST_IO;
    


    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}