#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

map<string, string> m;

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        for (int i = 0; i < EXT.size(); i ++)
            if ('a' <= EXT[i] && EXT[i] <= 'z')
                EXT[i] = char(EXT[i]-'a'+'A');
        m[EXT] = MT;
    }
    
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        string s = "";
        bool flag = false;
        for (int i = FNAME.size()-1; i >= 0; i --)
        {
            if (FNAME[i] == '.')
            {
                flag = true;
                break;
            }
            if ('a' <= FNAME[i] && FNAME[i] <= 'z')
                FNAME[i] = char(FNAME[i]-'a'+'A');
            s += FNAME[i];
        }
        reverse(s.begin(), s.end());
        if (m.count(s) != 0 && flag == true)
            cout << m[s] << endl;
        else cout << "UNKNOWN" << endl;
    }
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    //cout << "UNKNOWN" << endl; // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
}










