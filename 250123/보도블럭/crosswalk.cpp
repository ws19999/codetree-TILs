#include <iostream>
using namespace std;
int N, L;
int check(int i, int mapa[100][100]) {
	int j = 1;
	int l = -1;
	while (j < N) {
		if (mapa[i][j] == mapa[i][j - 1]) {
			j++;
			continue;
		}
		if (abs(mapa[i][j] - mapa[i][j - 1]) >= 2)return 0;
		if (mapa[i][j] > mapa[i][j - 1]) {
			for (int k = j - L; k <= j - 1; k++) {
				if (k < 0 or k<=l)return 0;
				if (mapa[i][k] != mapa[i][j - 1])return 0;
			}
			l = j - 1;
			j++;
		}
		else {
			for (int k = j - 1 + L; k > j; k--) {
				if (k >= N)return 0;
				if (mapa[i][k] != mapa[i][j])return 0;
			}
			l = j - 1 + L;
			j += L;
		}
	}
	return 1;
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int answer = 0;
	int mapa[100][100];
	int maparv[100][100];
	cin >> N>>L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mapa[i][j];
			maparv[j][i] = mapa[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		answer += check(i, mapa);
		answer += check(i, maparv);
	}
	cout << answer;
	return 0;
}