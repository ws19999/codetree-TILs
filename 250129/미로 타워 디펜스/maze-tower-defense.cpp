#include <iostream>
#include <vector>
using namespace std;
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
vector<pair<int, int>> positions;
int table[50][50],N,ans[4],lastposition;

void make_numbers() {
    int dxx[] = { 0,1,0,-1 }, dyy[] = { -1,0,1,0 };
    int d = 0;
    int x = (N + 1) / 2, y = (N + 1) / 2;
    for (int k = 1; k <= N - 1; k++) {
        for (int a = 0; a < 2; a++) {
            for (int t = 1; t <= k; t++) {
                x += dxx[d];
                y += dyy[d];
                positions.push_back(make_pair(x, y));
            }
            d = (d + 1) % 4;
        }
    }
    for (int k = 1; k <= N - 1; k++) {
        x += dxx[d];
        y += dyy[d];
        positions.push_back(make_pair(x, y));
    }
}

bool find_exploding_marbles(int i,int color) {
    int cnt = 1;
    for (int pos = i + 1; pos < lastposition; pos++) {
        if (table[positions[pos].first][positions[pos].second] != color)break;
        cnt++;
    }
    if (cnt >= 4) {
        for (int pos = i; pos < i + cnt; pos++)table[positions[pos].first][positions[pos].second] = 0;
        if(color<=3)ans[color] += cnt;
        return true;
    }
    return false;
}

void blizzard() {
    int d, s, x = (N + 1) / 2, y = (N + 1) / 2;
    cin >> d >> s;
    for (int a = 0; a < s; a++) {
        x += dx[d];
        y += dy[d];
        ans[table[x][y]]++;
        table[x][y] = 0;
    }
}

void move_marbles() {
    int l = 0, r = 0;
    while (r < lastposition) {
        if (!table[positions[r].first][positions[r].second])r++;
        else {
            int c = table[positions[r].first][positions[r].second];
            table[positions[l].first][positions[l].second] = c;
            l++;
            r++;
        }
    }
    for (int i = l; i < lastposition; i++)table[positions[i].first][positions[i].second] = 0;
    lastposition = l;
}

bool explode_marbles() {
    bool explode = false;
    for (int i = 0; i < lastposition; i++) {
        int color = table[positions[i].first][positions[i].second];
        if (color) {
            if (find_exploding_marbles(i, color))explode = true;
        }
    }
    return explode;
}

void change_marbles() {
    int color = 0, cnt = 0, pos=0;
    vector<pair<int, int>> marbles;
    for (int i = 0; i < lastposition; i++) {
        if (color != table[positions[i].first][positions[i].second]) {
            if (cnt)marbles.push_back(make_pair(cnt, color));
            color = table[positions[i].first][positions[i].second];
            cnt = 1;
        }
        else cnt++;
    }
    if (cnt)marbles.push_back(make_pair(cnt, color));
    for (auto i : marbles) {
        table[positions[pos].first][positions[pos].second] = i.first;
        pos++;
        table[positions[pos].first][positions[pos].second] = i.second;
        pos++;
        if (pos > N * N - 2)break;
    }
    lastposition = pos;
}
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M;
    cin >> N >> M;
    lastposition = N * N - 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];
        }
    }
    make_numbers();
    for (int i = 0; i < M; i++) {
        blizzard();
        while (true) {
            move_marbles();
            if (!explode_marbles())break;
        }
        change_marbles();
    }
    cout << ans[1]+2*ans[2]+3*ans[3];
    return 0;
}