#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int hp[N];        // highest prime
int canRemove[N]; // canRemove[i] --> if i can be removed - 1 else 0
int hsh[N];

vector<int> distinctPF(int x)
{
    vector<int> pfs;

    while (x > 1)
    {
        int pf = hp[x];
        while (x % pf == 0)
            x /= pf;
        pfs.push_back(pf);
    }

    return pfs;
}

int main()
{
    for (int i = 2; i < N; ++i)
    {
        if (hp[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                hp[j] = i;
            }
        }
    }

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
    {
        int y;
        cin >> y;
        hsh[y] = 1;
    }

    for (int i = 2; i < N; ++i)
    {
        if (hsh[i])
        {
            for (long long j = i; j < N; j *= i)
            {
                canRemove[j] = 1;
            }
        }
    }

    while (q--)
    {
        int x;
        cin >> x;

        vector<int> pfs = distinctPF(x);
        bool isPossible = false;
        for (int i = 0; i < pfs.size(); ++i)
        {
            for (int j = i; j < pfs.size(); ++j)
            {
                int product = pfs[i] * pfs[j];
                if (i == j && x % product != 0)
                    continue;
                int toRemove = x / product;
                if (canRemove[toRemove] == 1)
                {
                    isPossible = true;
                    break;
                }
            }
            if (isPossible)
                break;
        }
        cout << (isPossible ? "YES\n" : "NO\n");
    }

    return 0;
}
