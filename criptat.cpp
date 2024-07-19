#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

size_t f(size_t n, size_t l, vector<size_t> &litere_seamana, vector<size_t> &litere_cuvant, size_t maxlength) {
    vector< vector<size_t> > dp(n + 1, vector<size_t>(l + 1, 0));
    vector< vector<size_t> > dp2(n + 1, vector<size_t>(l + 1, 0));
    size_t solutia = 0;

    for (size_t i = 1; i <= n; i++) {
        for (size_t j = litere_cuvant[i - 1]; j <= l; j++) {

            dp[i][j] = dp[i - 1][j];
            dp2[i][j] = dp2[i - 1][j];
            size_t sol = dp[i - 1][j - litere_cuvant[i - 1]] + litere_cuvant[i - 1];
            size_t sol2 = dp2[i - 1][j - litere_cuvant[i - 1]] + litere_seamana[i - 1];

            if (dp[i][j] < sol) {
                dp[i][j] = sol;
                dp2[i][j] = sol2;
            } else if (dp[i][j] == sol) {
                dp2[i][j] = max(dp2[i][j], sol2);
            }

            if (solutia < dp[i][j] && dp[i][j] < 2 * dp2[i][j]) 
                solutia = dp[i][j];

            if (j < maxlength) {
                for (size_t k = i; k <= n; k++){
                    dp[k][j] = dp[i][j];
                    dp2[k][j] = dp2[i][j];
                }
            }

            //cout<<dp[i][j]<<" / "<<dp2[i][j]<<"   ";
        }
        //cout<<endl;
    }

    /*for (int i = 0; i <=n;i++) {
        for (int j=0;j<=l;j++){
            cout<<dp[i][j]<<" / "<<dp2[i][j]<<"   ";
        }cout<<endl;
    }*/

    return solutia;
}

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");
    size_t N, i, l = 0, solution = 0, myl = 0, nrtot = 0, maxlength = 0;
    fin >> N;
    vector<string> v(N);//fiecare cuvant
    vector<size_t> b(N);//lungimea fiecarui cuvant
    vector<size_t> nr(N);//litere care seamana din fiecare cuvant

    for (i = 0; i < N; i++) {
        fin >> v[i];
        l += v[i].length();
        b[i] = v[i].length();
        if (v[i].length() > maxlength)
            maxlength = v[i].length();
    }

    for (char c = 'a'; c <= 'z'; c++) {
        myl = 0;
        nrtot = 0;

        for (i = 0; i < N; i++) {
            nr[i] = 0;

            for (char c2 : v[i]) {
                if (c2 == c) {
                    nr[i] = nr[i] + 1;
                    nrtot += nr[i];
                }
            }
        }
        if (nrtot > 0)
            myl = f(N, l, nr, b, maxlength);

        if (myl > solution)
            solution = myl;
    }

    fout << solution << endl;
    return 0;
}
