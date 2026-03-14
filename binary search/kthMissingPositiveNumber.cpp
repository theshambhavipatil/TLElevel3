
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
pair<bool,int> possible(int mid,vector<int> &arr,int k){
    int val=arr[mid]-1-mid;
    // cout<<mid<<" "<<val<<endl;
    if(val>=k) return {true,val};
    return {false,-1};
}
int findKthPositive(vector<int>& arr, int k) {
    int start=0;
    int end=arr.size()-1;
    //nnnyyyyy
    int ans=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        pair<bool,int> p=possible(mid,arr,k);
        if(p.first){
            int val=p.second;
            // cout<<val<<" "<<k<<" "<<val-k<<endl;
            ans=min(ans,arr[mid]-1-val+k);
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    if (ans==INT_MAX) {
        int temp=arr[arr.size()-1];
        int num=temp-(arr.size()); //elements left
        int add=k-num;
        ans=arr[arr.size()-1]+add;
    }
    return ans;
}
void solve() {
    // Solution logic here
    int k=17;
    vector<int> arr={1,13,18};
    cout<<findKthPositive(arr,k)<<endl;
}

signed main() {
    FAST_IO;
    

    int t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}