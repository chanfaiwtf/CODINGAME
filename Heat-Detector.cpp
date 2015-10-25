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
    int w, h, n, x0, y0;
    //int W; // width of the building.
    //int H; // height of the building.
    cin >> w >> h; cin.ignore();
    //int N; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    //int X0;
    //int Y0;
    cin >> x0 >> y0; cin.ignore();
    
    int x1, y1, x2, y2;
    x1 = y1 = 0;
    x2 = w;
    y2 = h;
    // game loop
    while (1)
    {
        string s; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> s; cin.ignore();
        
        for (int i = 0; i < s.size(); i ++)
        {
            if (s[i] == 'L')
                x2 = x0;
            if (s[i] == 'R')
                x1 = x0+1;
            if (s[i] == 'U')
                y2 = y0;
            if (s[i] == 'D')
                y1 = y0+1;
        }
        
        x0 = (x1+x2)/2;
        y0 = (y1+y2)/2;
        
        cout << x0 << " " << y0 << endl;
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        //cout << "0 0" << endl; // the location of the next window Batman should jump to.
    }
}



















