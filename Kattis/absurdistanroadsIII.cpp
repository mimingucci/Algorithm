#include <bits/stdc++.h>
using namespace std;
struct node {
    bool visited;
    int degree;
    vector<int> neighbors;
};

void removeleaves(vector<node>& v) {
    stack<int> s;

    for(int i = 0; i < v.size(); i++) {
        if(v[i].degree == 1) {
            s.push(i);
        }
    }

    while(!s.empty()) {
        int curr = s.top();
        s.pop();

        v[curr].visited = true;
        for(int i = 0; i < v[curr].neighbors.size(); i++) {
            int neighbor = v[curr].neighbors[i];
            if(!v[neighbor].visited) {
                v[neighbor].degree--;
                if(v[neighbor].degree == 1) {
                    s.push(neighbor);
                }
                cout << curr << " " << neighbor << endl;
            }
        }
    }

}

void removecycles(vector<node>& v, int start) {
    stack<int> s;
    s.push(start);

    while(!s.empty()) {
        int curr = s.top();
        s.pop();

        for(int i = 0; i < v[curr].neighbors.size(); i++) {
            int neighbor = v[curr].neighbors[i];
            if(!v[neighbor].visited) {
                s.push(neighbor);
                v[curr].visited = true;
                cout << curr << " " << neighbor << endl;
                break;
            }
        }
    }

    for(int i = 0; i < v[start].neighbors.size(); i++) {
        int neighbor = v[start].neighbors[i];
        if(!v[neighbor].visited) {
            cout << neighbor << " " << start << endl;
            break;
        }
    }
}


main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    node empty = {false, 0, {}};
    vector<node> v(n+2, empty);

    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        v[n1].neighbors.push_back(n2);
        v[n2].neighbors.push_back(n1);

        v[n1].degree++;
        v[n2].degree++;
    }
    n++;
    removeleaves(v);
    for(int i = 1; i < n+1; i++) {
        if(!v[i].visited) {
            removecycles(v, i);
        }
    }
}