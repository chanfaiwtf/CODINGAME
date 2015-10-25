#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    getline(cin, temps);
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << temps << endl;
        return 0;
    }
    int ans = 9999999, now = 0, neg = 0;
    for (int i = 0; i < temps.size(); i ++) {
        //cout << temps[i] << " ";
        if (temps[i] == ' ') {
            if (abs(now) < abs(ans)) {
                ans = now;
                if (neg == 1)
                    ans = now = -now;
            }
            if (abs(now) == abs(ans)) {
                if (ans < 0 && neg == 0)
                    ans = now;
            }
            now = 0;
            neg = 0;
            continue;
        }
        if (temps[i] == '-') {
            neg = 1;
            continue;
        }
        now = now*10 + temps[i] - '0';
    }
    
    cout << ans << endl;
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    //cout << "result" << endl;
}














