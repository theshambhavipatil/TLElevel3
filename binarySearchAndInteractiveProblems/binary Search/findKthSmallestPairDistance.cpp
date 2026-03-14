
#include <bits/stdc++.h>
#define int long long
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

int getVal(vector<int> &nums,int val,int startIdx) {
    int start = startIdx;
    int end = nums.size() - 1;
    int ans = INT_MAX;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= val) {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

bool possible(vector<int> &nums,int k,int dist) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        int temp=getVal(nums,nums[i]+dist,i+1);
        cout<<"idx "<<i<<" temp"<<temp<<" dist"<<dist<<endl;
        if (temp!=INT_MAX) {
            count+=nums.size()-temp;
        }
    }
    cout<<"count"<<count<<endl;
    if (count>=k){ return true;}
    return  false;
}

int smallestDistancePair(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int start = 0;
    int end = nums[nums.size()-1]-nums[0];;
    while (start < end) {
        int mid = start + (end - start) / 2;
        cout<<"start "<<start<<" mid "<<mid<<" end"<<end<<endl;
        if (possible(nums, k, mid)) {
            start=mid;
        }
        else {
            end=mid;
        }
    }

    return start;
}
void solve() {
    // Solution logic here
    vector<int> nums={1,6,1};
    int k=3;
    int ans=smallestDistancePair(nums, k);
    cout<<ans<<endl;
}

signed main() {
    FAST_IO;



    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}
