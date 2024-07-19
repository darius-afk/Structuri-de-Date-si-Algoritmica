#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");
    int N, M, i = 0, j = 0, nr = 0, sum = 0, sum2 = 0;
    fin >> N;
    int a[N];

    for (i = 0; i < N; i++) {
        fin >> a[i];
    }

    fin >> M;
    int b[M];

    for (j = 0; j < M; j++) {
        fin >> b[j];
    }

    i = 0;
    j = 0;

    while (i < N && j < M) {
        sum = a[i];
        sum2 = b[j];

        while (i < N && j < M && sum != sum2) {
            if (sum < sum2) {
                sum += a[++i];
            } else {
                sum2 += b[++j];
            }
        }

        if (sum == sum2) {
            nr++;
            sum = 0;
            sum2 = 0;   
            i++;
            j++;
        }
    }

    while (i < N) {
        sum += a[i++];
    }

    while (j < M) {
        sum2 += b[j++];
    }
    
    if (sum != sum2) {
        fout << "-1\n";
        return 0;
    }

    fout << nr << '\n';
    return 0;
}