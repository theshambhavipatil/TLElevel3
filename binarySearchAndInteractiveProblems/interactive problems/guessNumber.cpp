
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

int toGuess=100; //the answer that we want to guess
bool testing=true; // set to true only while debugging

char interactor(int query) {
    if (query == toGuess) {
        return '=';
    }
    else if (query > toGuess) {
        return '>';
    }
    else {
        return '<';
    }
}

char ask(int x) {
    cout<<"? "<<x<<endl;
    if (testing) {//only for debugging
        cout<<interactor(x)<<endl;
        return interactor(x);
    }
    char c; cin>>c; return c; // for my input judge returns an output
}

void solve() {
    // Solution logic here
    int l=1 , r=1e9 , ans=-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        char result=ask(mid); //in interactive problems we dont print our answers we give them to the online judge
         if(result=='<') {
             //our number is smaller than the ans
             l=mid+1;
         }
        else if(result=='>') {
            r=mid-1;
        }
        else {
            ans=mid;
            break;
        }
    }

    cout<<"! "<<ans<<endl;
}

signed main() {
    FAST_IO;

    // always remove for interactive problems
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("Error.txt", "w", stderr);
//#endif

    int t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}