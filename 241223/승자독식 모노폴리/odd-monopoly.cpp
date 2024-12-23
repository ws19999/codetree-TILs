#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

pair<int, int> table[20][20];
// table[x][y] = (owner, turn) 
//   - owner: 해당 칸을 현재 점유하고 있는 플레이어 번호(0이면 없음)
//   - turn : 해당 칸을 마지막으로 점유한 턴

int n, m, k;
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
int dirs[401][5][4];
// dirs[playerNum][현재 방향d][우선순위 i] = 실제 이동방향(1~4)

map<int, tuple<int, int, int>> players;
// players[playerID] = (x, y, d)

void turn(int t) {
    //    - t - table[x][y].second > k 이면 owner=0으로 해제
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // owner가 있다면, k턴 지나면 해제
            if (table[i][j].first != 0) {
                if (t - table[i][j].second > k) {
                    table[i][j] = make_pair(0, -1);
                }
            }
        }
    }

    //    nextPos[playerID] = (nx, ny, ndir)
    //    실제 table에 바로 반영하지 않고, 다 계산한 뒤에 충돌 처리
    map<int, tuple<int, int, int>> nextPos;

    // 2-1. 각 플레이어가 "다음에 이동할 자리(nx, ny)" 계산
    for (auto& p : players) {
        int num = p.first;
        int x = get<0>(p.second);
        int y = get<1>(p.second);
        int d = get<2>(p.second);

        bool moved = false;
        int nx = x, ny = y, ndir = d;

        // (A) "빈 칸(또는 향기가 사라진 칸)" 먼저 탐색
        for (int i = 0; i < 4; i++) {
            int nd = dirs[num][d][i];
            int tx = x + dx[nd];
            int ty = y + dy[nd];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;

            // 테이블에서 해당 칸이 비어 있으면 이동 가능
            // ("독점 계약이 유효하지 않은 칸" 또는 "아예 주인 없는 칸")
            if (table[tx][ty].first == 0) {
                nx = tx;
                ny = ty;
                ndir = nd;
                moved = true;
                break;
            }
        }

        // (B) 만약 (A)에서 못 움직였으면, "본인이 점유 중인 칸" 탐색
        if (!moved) {
            for (int i = 0; i < 4; i++) {
                int nd = dirs[num][d][i];
                int tx = x + dx[nd];
                int ty = y + dy[nd];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;

                // "이 칸의 owner가 나 자신"이면 이동 가능
                if (table[tx][ty].first == num) {
                    nx = tx;
                    ny = ty;
                    ndir = nd;
                    moved = true;
                    break;
                }
            }
        }

        // 결국 이동에 성공했든 못했든 "이동 목표"는 (nx, ny, ndir)
        //   - 못 움직인 경우 (x, y, d)가 그대로 들어갈 수 있음
        nextPos[num] = make_tuple(nx, ny, ndir);
    }

    //      nextPos에 따르면 여러 플레이어가 (nx, ny)에 몰릴 수 있음
    //      => 가장 ID가 작은 플레이어만 살아남고 나머지는 제거
    //      (동시에 이동한 것이므로, 이동 자체는 다 시도했다고 보는 것)
    map< pair<int, int>, vector<int> > conflicts;
    for (auto& np : nextPos) {
        int num = np.first;
        int nx = get<0>(np.second);
        int ny = get<1>(np.second);
        conflicts[{nx, ny}].push_back(num);
    }

    // (새로운 players 컨테이너) 최종 살아남은 플레이어만 여기에 담을 예정
    map<int, tuple<int, int, int>> newPlayers;

    for (auto& c : conflicts) {
        auto& v = c.second; // 이 위치로 이동한 플레이어 ID들의 목록
        if (v.size() == 1) {
            // 한 명만 이동 => 충돌 없음
            int winner = v[0];
            newPlayers[winner] = nextPos[winner];
        }
        else {
            // 여러 명이 몰렸으면, 가장 ID가 작은 플레이어만 살아남음
            sort(v.begin(), v.end());
            int winner = v[0];
            newPlayers[winner] = nextPos[winner];
        }
    }

    //      우선 전체 칸 owner를 다 0으로 초기화한 뒤, 살아남은 애들만 다시 세팅
    //      (또는 기존 table을 지우진 않고, 아래에서 덮어써도 됨)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j].first != 0) {
                // 어차피 다시 덮어쓸 것이라면 초기화해도 되고, 
                // 문제 조건에 맞춰서 처리만 하셔도 됩니다.
                // 여기서는 편의상 계속 유지하되, 필요한 곳만 덮어씁니다.
            }
        }
    }

    // 살아남은 플레이어 위치에 대해 table 업데이트
    //   - 테이블에 (owner, t) 기록
    for (auto& p : newPlayers) {
        int num = p.first;
        int nx = get<0>(p.second);
        int ny = get<1>(p.second);
        int nd = get<2>(p.second);
        table[nx][ny] = make_pair(num, t);  // 이번 턴에 점유(향기 남김)
    }

    players = newPlayers;
    m = (int)players.size();
}

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            table[i][j] = make_pair(0, -1); // 처음엔 아무도 점유X
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num) {
                // 플레이어 번호 num이 (i, j)에 있음
                table[i][j] = make_pair(num, 0);
                players[num] = make_tuple(i, j, 0); // 방향은 일단 0(혹은 문제에서 정한 방식)
            }
        }
    }
    // 플레이어 초기 방향 입력
    for (int i = 1; i <= m; i++) {
        cin >> get<2>(players[i]);
    }
    // dirs[playerID][d][0..3] 입력
    for (int i = 1; i <= m; i++) {
        for (int d = 1; d <= 4; d++) {
            for (int l = 0; l < 4; l++) {
                cin >> dirs[i][d][l];
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    for (int t = 1; t < 1000; t++) {
        turn(t);
        if (players.size() == 1) {
            cout << t;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
