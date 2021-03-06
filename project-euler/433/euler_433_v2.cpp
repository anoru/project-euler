#include <cstdio>

typedef long long ll;

static ll n;

struct Item
{
    ll c[2], m;
};

Item lst[5000001];

static void gen(const ll y, const ll x, const ll v)
{
    if (v <= 10)
    {
        printf("%lld %lld %lld\n", y, x, v);
        fflush(stdout);
    }
    for (ll q = y; q <= n; q += x)
    {
        lst[q].c[x > lst[q].m ] += v;
        gen(q+x, q, v+1);
    }
}

static ll S(const ll new_n)
{
    n = new_n;
    for (ll y = 1; y <= n ; y++)
    {
        lst[y].c[0] = lst[y].c[1] = 0;
        lst[y].m = n % y;
    }
    for (ll x = 1; x <= n; x++)
    {
        printf("x=%lld\n", x);
        gen(x << 1, x, 1);
    }
    ll ret = 0;
    ret += n;
    for (ll y = 1; y <= n; ++y)
    {
        const auto item = lst[y];
        const auto ss = item.m + item.c[0];
        const auto s = item.c[0] + item.c[1] + y;
        const auto delta = ((ss + s * ((n - y) / y)) << 1) + (n-y);
        ret += delta;
    }
    printf("n=%lld ret = %lld\n", n, ret);

    return ret;
}
int main()
{
    S(10);
    S(100);

    S(5000000);

    return 0;
}
