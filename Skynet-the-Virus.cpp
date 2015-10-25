#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int n, l, e;
bool a[505][505];
set<int> s;

int main()
{
    //int N; // the total number of nodes in the level, including the gateways
    //int L; // the number of links
    //int E; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();
    memset(a, 0, sizeof a);
    s.clear();
    for (int i = 0; i < l; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        a[N1][N2] = a[N2][N1] = 1;
    }
    for (int i = 0; i < e; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        s.insert(EI);
    }
    
    // game loop
    while (1) {
        int x; // The index of the node on which the Skynet agent is positioned this turn
        cin >> x; cin.ignore();
        
        int bef = -1, tar = -1;
        queue<int> q;
        vector<bool> b;
        b.resize(n, 0);
        q.push(x);
        b[x] = 1;
        while (!q.empty())
        {
            int t = q.front();
            for (int i = 0; i < n; i ++)
            {
                if (a[t][i] == 0) continue;
                if (s.count(i) == 0)
                {
                    q.push(i);
                    b[i] = 1;
                    continue;
                }
                bef = t;
                tar = i;
                break;
            }
            if (tar != -1) break;
            q.pop();
        }
        cout << bef << " " << tar << endl;
        a[bef][tar] = a[tar][bef] = 0;
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        //cout << "0 1" << endl; // Example: 0 1 are the indices of the nodes you wish to sever the link between
    }
}