#include <iostream>
#include <deque>
using namespace std;
int n,k,zeros=0,peoplecnt=0;
deque<int> rail;
deque<int> people;
void first() {
	rail.push_front(rail.back());
	rail.pop_back();
	for (int i = 0; i < peoplecnt; i++) {
		people[i]++;
	}
	if (!people.empty()) {
		if (people.back() == n-1) {
			people.pop_back();
			peoplecnt--;
		}
	}
}
void second() {
	for (int i = peoplecnt - 1; i >= 0; i--) {
		if (i < peoplecnt - 1) {
			if (people[i + 1] != people[i] + 1 and rail[people[i] + 1] > 0) {
				people[i]++;
				rail[people[i]]--;
				if (rail[people[i]] == 0)zeros++;
				continue;
			}
			else continue;
		}
		if (rail[people[i] + 1] > 0) {
			people[i]++;
			rail[people[i]]--;
			if (rail[people[i]] == 0)zeros++;
		}
	}
	if (!people.empty()) {
		if (people.back() == n-1) {
			people.pop_back();
			peoplecnt--;
		}
	}
}
void third() {
	if (rail.front() != 0) {
		if (people.empty()) {
			people.push_front(0);
			peoplecnt++;
			rail.front()--;
			if (rail.front() == 0)zeros++;
		}
		else if (people.front() != 0) {
			people.push_front(0);
			peoplecnt++;
			rail.front()--;
			if (rail.front() == 0)zeros++;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>k;
	for (int i = 0; i < 2 * n; i++) {
		int stability;
		cin >> stability;
		rail.push_back(stability);
	}
	int tc = 0;
	while (true) {
		tc++;
		first();
		second();
		third();
		if (zeros >= k)break;
	}
	cout << tc;
	return 0;
}