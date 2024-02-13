// hackerearth Question: https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int hsh[N];
int multiples_ct[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }

    // sieve
    for (int i = 1; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
        {
            multiples_ct[i] += hsh[j];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int p, q;
        cin >> p >> q;
        long long lcm = p * 1ll * q / __gcd(p, q);

        long ans = multiples_ct[p] + multiples_ct[q];
        if (lcm < N)
            ans -= multiples_ct[lcm];

        cout << ans << endl;
    }

    return 0;
}
