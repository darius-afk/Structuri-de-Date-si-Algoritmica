#include<iostream>
#include<fstream>
using namespace std;

long long fastPow(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result % mod;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    long long K, X, n = 1000000007;
    char T;
    fin >> K;
    fin >> X >> T;
    long long dp = 1;
    if (T == 'H') {
        dp = 6;
        dp = (dp * fastPow(3, X - 1, n)) % n;
    } else {
        dp = 3;
        dp = (dp * fastPow(2, X - 1, n)) % n;
    }

    for (int i = 1; i < K; i++) {
        char prevT = T;
        fin >> X >> T;
        if (T == prevT && T == 'V') {
            dp = (dp * fastPow(2, X, n)) % n;
        }
        if (T == prevT && T == 'H') {
            dp = (dp * fastPow(3, X, n)) % n;
        }
        if (T != prevT && T == 'V') {
            dp = (dp * fastPow(2, X - 1, n)) % n;
        }
        if (T != prevT && T == 'H') {
            dp = (dp * 2 * fastPow(3, X - 1, n)) % n;
        }
    }

    dp = dp % n;

    fout << dp << '\n';
    return 0;
}
