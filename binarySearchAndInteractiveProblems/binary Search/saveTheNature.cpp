
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

bool possible(int mid, vector<int> &v,int x,int y,int a,int b,int n,int k) {
    int val=lcm(a,b);
    int num1=mid/a;
    int num2=mid/b;
    int num3=mid/val;


    // cout<<"wasted "<<wasted<<endl;
    num1-=num3;
    num2-=num3;
    mid=num1+num2+num3;
    // cout<<"mid= "<<mid<<endl;
    int count=0;
    int idx=0;
    for(int i=0;i<num3;i++) {
        if (idx>=mid) {
            break;
        }
        count+=(v[idx]/100)*(x+y);
        // cout<<(v[idx]/100)*(x+y)<<" ";
        idx++;
    }
    if (x>y) {
        for(int i=0;i<num1;i++) {
            if (idx>=mid) {
                break;
            }
            count+=(v[idx]/100)*x;
            // cout<<(v[idx]/100)*x<<" ";

            idx++;
        }
        for(int i=0;i<num2;i++) {
            if (idx>=mid) {
                break;
            }
            count+=(v[idx]/100)*y;
            // cout<<(v[idx]/100)*y<<" ";

            idx++;
        }
    }
    else {
        for(int i=0;i<num2;i++) {
            if (idx>=mid) {
                break;
            }
            count+=(v[idx]/100)*y;
            // cout<<(v[idx]/100)*y<<" ";

            idx++;
        }
        for(int i=0;i<num1;i++) {
            if (idx>=mid) {
                break;
            }
            count+=(v[idx]/100)*x;
            // cout<<(v[idx]/100)*x<<" ";

            idx++;
        }

    }


    // cout<<k<<" "<<count<<endl;
    if (count>=k) {
        return true;
    }
    return false;



}

void solve() {
    // Solution logic here
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int x, a;
    cin >> x >> a;
    int y, b;
    cin >> y >> b;
    int k;
    cin >> k;

    int ans=INT64_MAX;
    int start = 1;
    int end = n;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        // cout<<"mid "<<mid<<"start "<<start<<" end"<<end<<endl;
        if (possible(mid, v, x, y, a, b,n,k)) {
            ans=min(ans,mid);
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }

    if (ans==INT64_MAX) {
        ans=-1;
    }

    cout<<ans<<endl;
}

signed main() {
    FAST_IO;



    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
