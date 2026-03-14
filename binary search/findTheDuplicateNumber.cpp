
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


bool check(int mid,vector<int> &v) {
    int count=0;
    for(int i=0;i<v.size();i++) {
        if(v[i]==mid) count++;
    }
    if (count>mid) {
        return true;
    }
    return false;
}


int findDuplicate(vector<int>& nums) {
    int low=1;
    int high=nums.size()-1;
    int ans=INT_MAX;
    while (low<=high) {
        int mid = low + (high-low)/2;
        if (check(mid,nums)) {
            ans=min(ans,mid);
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return ans;
}


void solve() {
    // Solution logic here
    vector<int> nums={3,1,3,4,2};
    int ans=findDuplicate(nums);
    cout<<ans<<endl;
}

signed main() {
    FAST_IO;
    
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