#include <iostream>
#include <unordered_map>
using namespace std;

struct DoublyLinkedList {
    struct Node {
        Node* prev;
        Node* next;
        pair<int,int> data;
        Node(int id, int w): prev(nullptr), next(nullptr), data(id,w) {}
    };
    
    Node* head;
    Node* tail;
    int size;

    DoublyLinkedList(): head(nullptr), tail(nullptr), size(0) {}

    void push_back(pair<int,int> val) {
        Node* newNode = new Node(val.first, val.second);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if(!head) return;
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
        size--;
    }

    void erase(Node* node) {
        if(!node) return;
        if(node->prev) node->prev->next = node->next;
        else head = node->next;
        if(node->next) node->next->prev = node->prev;
        else tail = node->prev;
        delete node;
        size--;
    }
    void splice_front_from(Node* start) {
        if(!start || start == head) return;

        Node* startPrev = start->prev;
        if (startPrev) {
            startPrev->next = nullptr;
            tail = startPrev;
        }

        Node* oldHead = head;
        head = start;
        head->prev = nullptr;

        Node* endNode = head;
        while(endNode->next) endNode = endNode->next;

        if(oldHead) {
            oldHead->prev = endNode;
            endNode->next = oldHead;
        } else {
            tail = endNode; 
        }
	}

    void splice_all_back(DoublyLinkedList &other) {
        if(!other.head) return; 
        if(!head) {
            head = other.head;
            tail = other.tail;
        } else {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
        size += other.size;
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
};

int boxes[100000];
int weights[100000];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q, n, m, w_max, answer = 0, r_id, f_id, b_num;
    cin >> q;
    DoublyLinkedList belt[11];
    bool available[11] = { false };
    unordered_map<int, pair<int,DoublyLinkedList::Node*>> keys;

    for (int query = 1; query <= q; query++) {
        int Q;
        cin >> Q;
        switch (Q) {
        case 100:
            cin >> n >> m;
            for (int i = 0; i < n; i++)cin >> boxes[i];
            for (int i = 0; i < n; i++) cin >> weights[i];
            for (int i = 1; i <= m; i++) {
                available[i] = true;
                for (int j = (i - 1) * n / m; j < i * n / m; j++) {
                    belt[i].push_back({boxes[j], weights[j]});
                    keys[boxes[j]] = {i, belt[i].tail};
                }
            }
            break;
        case 200:
            answer = 0;
            cin >> w_max;
            for (int i = 1; i <= m; i++) {
                if (!belt[i].head) continue;
                if (belt[i].head->data.second <= w_max) {
                    keys[belt[i].head->data.first].first = 0;
                    answer += belt[i].head->data.second;
                    belt[i].pop_front();
                }
                else {
                    DoublyLinkedList::Node* front = belt[i].head;
                    belt[i].head = front->next;
                    if(belt[i].head) belt[i].head->prev = nullptr;
                    else belt[i].tail = nullptr;

                    front->next = nullptr;
                    front->prev = belt[i].tail;
                    if(belt[i].tail) belt[i].tail->next = front;
                    else belt[i].head = front;
                    belt[i].tail = front;
                    keys[front->data.first].second = front;
                }
            }
            cout << answer << "\n";
            break;
        case 300:
            cin >> r_id;
            if (keys[r_id].first == 0) cout << -1 << "\n";
            else {
                int l = keys[r_id].first;
                DoublyLinkedList::Node* nd = keys[r_id].second;
                keys[r_id].first = 0;
                belt[l].erase(nd);
                cout << r_id << "\n";
            }
            break;
        case 400:
            cin >> f_id;
            if (keys[f_id].first == 0) cout << "-1\n";
            else {
                int l = keys[f_id].first;
                DoublyLinkedList::Node* start = keys[f_id].second;
                belt[l].splice_front_from(start);
                cout << l << "\n";
            }
            break;
        case 500:
            cin >> b_num;
            if (available[b_num] == false)cout << "-1\n";
            else {
                available[b_num] = false;
                int l = b_num;
                while (!available[l]) {
                    l++;
                    if (l > m) l = 1;
                }
                for (auto it = belt[b_num].head; it; it = it->next) {
                    keys[it->data.first].first = l;
                }
                belt[l].splice_all_back(belt[b_num]);
                cout << b_num << "\n";
            }
            break;
        }
    }
    return 0;
}
