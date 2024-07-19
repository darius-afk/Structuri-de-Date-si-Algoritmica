#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

double find_best(vector<int> &pret, int N, int K) {
    int i = 1;
    vector<double> dp(N);

    dp[0] = pret[0];

    if (N > 1) {
        dp[1] = pret[0] + pret[1] - (double)(min(pret[0], pret[1])) / 2.0;
        i = 2;
    }

    if (N > 2) {
        double sol1 = dp[0] + pret[1] + pret[2] - (double)(min(pret[1], pret[2])) / 2.0;
        double sol2 = dp[1] + pret[2];
        double sol3 = pret[0] + pret[1] + pret[2] - min(pret[0], min(pret[1], pret[2]));
        dp[2] = min(sol1, min(sol2, sol3));
        i = 3;
    }

    while (i < N) {
        double sol1 = dp[i - 2] + pret[i - 1] + pret[i] - (double)(min(pret[i - 1], pret[i])) / 2.0;
        double sol2 = dp[i - 1] + pret[i];
        double sol3 = dp[i - 3] + pret[i - 2] + pret[i - 1] + pret[i] - min(pret[i - 2], min(pret[i - 1], pret[i]));

        if (sol2 <= sol1 && sol2 <= sol3) {
            dp[i] = sol2;
        } else if (sol1 <= sol2 && sol1 <= sol3) {
            dp[i] = sol1;
        } else {
            dp[i] = sol3;
        }

        i++;
    }
    return dp[i - 1];
}

int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");
    int N, K, i, priceK = 0;

    fin >> N >> K;

    vector<int> price(N);

    for (i = 0; i < N; i++) {
        fin >> price[i];
        priceK += price[i];
    }

    if (K == N) {
        fout << fixed << setprecision(1) << priceK << '\n';
        return 0;
    } else if (K > N) {
        fout << fixed << setprecision(1) << -1 << '\n';
        return 0;
    }

    fout << fixed << setprecision(1) << find_best(price, N, K) << '\n';

    return 0;
}