
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


int findInteger(vector<int> &v1,vector<int> &v2,int idx) {
    int start1=0;
    int end1=v1.size()-1;
    while(start1<=end1) {
        int mid1=start1+(end1-start1)/2;
        int val1=v1[mid1];
        int start2=0;
        int end2=v2.size()-1;
        int mid2;
        while (start2<=end2) {
            mid2=start2+(end2-start2)/2;
            int val2=v2[mid2];
            if(val1==val2) {
               break;
            }
            if(val1<val2) {
                end2=mid2-1;
            }
            else {
                start2=mid2+1;
            }
        }
        if (mid1+mid2+1==idx) {
            return val1;
        }

        return v2[idx];
    }
}


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int start1 = 0;
    int end1 = nums1.size();

    int totalSize = nums1.size() + nums2.size();
    if (totalSize % 2 == 0) {
        vector<int> find;
        find.push_back(totalSize / 2);
        find.push_back(totalSize / 2 + 1);


        int ans = 0;
        for (int i = 0; i < find.size(); i++) {
            bool flag = false;
            while (start1 <= end1) {
                int start2 = 0;
                int end2 = nums2.size();
                int ans1 = INT_MIN;
                int mid1 = start1 + (end1 - start1) / 2;
                int val1 = nums1[mid1];
                int mid2;
                while (start2 <= end2) {
                    mid2 = start2 + (end2 - start2) / 2;
                    int val2 = nums2[mid2];
                    if (val2 <= val1) {
                        ans1 = max(ans1, val2);
                        start1 = mid1 + 1;
                    } else {
                        end1 = mid1 - 1;
                    }
                }
                int count = mid1 + mid2 + 2;
                if (count == find[i]) {
                    ans1 = nums1[mid1];
                    ans += ans1;
                    flag = true;
                    break;
                } else if (count > find[i]) {
                    end1 = mid1 - 1;
                } else {
                    start1 = mid1 + 1;
                }
            }
            if (flag == false) {
                ans += nums2[find[i]];
            }
        }
        return (double) ans / 2 ;
    } else {
        int ans = 0;
        int find = totalSize / 2;
        bool flag = false;
        while (start1 <= end1) {
            int start2 = 0;
            int end2 = nums2.size();
            int ans1 = INT_MIN;
            int mid1 = start1 + (end1 - start1) / 2;
            int val1 = nums1[mid1];
            int mid2;
            while (start2 <= end2) {
                mid2 = start2 + (end2 - start2) / 2;
                int val2 = nums2[mid2];
                if (val2 <= val1) {
                    ans1 = max(ans1, val2);
                    start1 = mid1 + 1;
                } else {
                    end1 = mid1 - 1;
                }
            }
            int count = mid1 + mid2 + 2;
            if (count == find) {
                ans1 = nums1[mid1];
                ans += ans1;
                flag = true;
                break;
            } else if (count > find) {
                end1 = mid1 - 1;
            } else {
                start1 = mid1 + 1;
            }
        }
        if (flag == false) {
            ans += nums2[find];
        }
        return (double) ans / 2 ;
    }
}

void solve() {
    // Solution logic here
}

signed main() {
    FAST_IO;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
