#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

const char iname[] = "triunghi.in";
const char oname[] = "triunghi.out";

const int MAX_N = 1005;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++ i)
#define FORR(i, b, a) for (int i = (b); i >= (a); -- i)

int T[MAX_N][MAX_N], a[MAX_N][MAX_N], b[MAX_N][MAX_N];

int main(void) {
    FILE *fi = fopen(iname, "r");
    int n;

    assert(fscanf(fi, "%d", &n) == 1);
    assert(1 <= n && n <= 1000);
    FOR (i, 1, n) FOR (j, 1, i)
        assert(fscanf(fi, "%d", &T[i][j]) == 1);
    fclose(fi);

    FOR (j, 1, n)  a[n][j] = b[n][j] = T[n][j];
    FORR (i, n - 1, 1) {
        FOR (j, 1, i) {
            a[i][j] = a[i + 1][j + 1] + T[i][j],
            b[i][j] = b[i + 1][j] + T[i][j];
        }
    }
    int ans = 0;
    for (int i = 1, j = 1; i < n; ) {
        int cost_diag = (2 * a[i][j] - T[i][j] - T[n][j+n-i]) + (a[i][j] + a[i + 1][j] - T[n][j+n-i]) * (n - i);
        int cost_down = (2 * b[i][j] - T[i][j] - T[n][j]) + (b[i][j] + b[i + 1][j + 1] - T[n][j]) * (n - i);
        if (cost_down < cost_diag)
            i ++, j ++, ans += cost_down;
        else
            i ++, ans += cost_diag;
    }

    fprintf(fopen(oname, "w"), "%d\n", ans);
    printf("%d\n", ans);

    return 0;
}

