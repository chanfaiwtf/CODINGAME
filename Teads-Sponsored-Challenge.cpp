#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<vector<int> > a;

int main()
{
    int n; // the number of adjacency relations
    cin >> n; cin.ignore();
    
    int m = 0;
    a.resize(2000002);
    
    for (int i = 0; i < n; i++)
    {
        int x; // the ID of a person which is adjacent to yi
        int y; // the ID of a person which is adjacent to xi
        cin >> x >> y; cin.ignore();
        a[x].push_back(y);
        a[y].push_back(x);
        m = max(m, max(x, y));
    }
    
    int k = m;
    vector<int> f;
    f.resize(m+2, -1);
    
    // first bfs
    vector<bool> b;
    b.resize(m+2, 0);
    queue<int> q;
    q.push(k);
    b[k] = 1;
    f[k] = 0;
    while (!q.empty())
    {
        int fr = q.front();
        for (int i = 0; i < a[fr].size(); i ++)
        {
            if (b[a[fr][i]] == 0)
            {
                q.push(a[fr][i]);
                b[a[fr][i]] = 1;
                f[a[fr][i]] = f[fr]+1;
            }
        }
        q.pop();
    }
    
    int maxf = f[m];
    for (int i = 0; i <= m; i ++)
        if (f[i] > maxf)
            {
                maxf = f[i];
                k = i;
            }
    
    f.clear();
    f.resize(m+2, -1);
    b.clear();
    b.resize(m+2, 0);
    
    // second bfs
    q.push(k);
    b[k] = 1;
    f[k] = 0;
    while (!q.empty())
    {
        int fr = q.front();
        for (int i = 0; i < a[fr].size(); i ++)
        {
            if (b[a[fr][i]] == 0)
            {
                q.push(a[fr][i]);
                b[a[fr][i]] = 1;
                f[a[fr][i]] = f[fr]+1;
            }
        }
        q.pop();
    }
    
    maxf = f[m];
    for (int i = 0; i <= m; i ++)
        if (f[i] > maxf)
        {
            maxf = f[i];
            k = i;
        }
    
    int ans;
    ans = maxf/2 + maxf%2;
    cout << ans << endl;
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    //cout << "1" << endl; // The minimal amount of steps required to completely propagate the advertisement
}