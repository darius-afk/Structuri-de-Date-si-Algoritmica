#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<climits>
using namespace std;

long double calculateMinPower(long long P[], long long C[], long long N, long double current) {
    long double minPower = INFINITY;
    for (long long i = 0; i < N; i++) {
        long double power = P[i] - abs(current - C[i]);
        minPower = min(minPower, power);
    }
    return minPower;
}

int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    long long N, Pmax = LONG_LONG_MIN, Cmin = LONG_LONG_MAX, Cmax = LONG_LONG_MIN, Pmin = LONG_LONG_MAX;
    long double maxpower = LONG_LONG_MIN;
    //long double curent_optim;

    fin >> N;
    long long P[N], C[N];

    for (long long i = 0; i < N; i++) {
        fin >> P[i];
        if (P[i] > Pmax) Pmax = P[i];
        if (P[i] < Pmin) Pmin = P[i];
    }

    for (long long i = 0; i < N; i++) {
        fin >> C[i];
        if (C[i] < Cmin) Cmin = C[i];
        if (C[i] > Cmax) Cmax = C[i];
    }

    long double left = Cmin;
    long double right = Pmax;

    if (Cmin > Pmax) {
        left = Pmin;
        right = Cmax;
    }

    while (left <= right) {
        long double mid = (left + right) / 2;
        long double power = calculateMinPower(P, C, N, mid);
        if (power > maxpower) {
            maxpower = power;
        }
        if (calculateMinPower(P, C, N, mid - 0.1) > power) {
            right = mid - 0.1;
        } else {
            left = mid + 0.1;
        }
    }

    fout << fixed << setprecision(1) << maxpower << "\n";

    return 0;
}