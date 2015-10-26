#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int a[20];

int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    memset(a, 0, sizeof a); // the position of elevators
    for (int i = 0; i < nbElevators; i++)
    {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        a[elevatorFloor] = elevatorPos;
    }
    
    // game loop
    while (1)
    {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        
        if (cloneFloor == -1 || clonePos == -1 || direction == "NONE")
        {
            cout << "WAIT" << endl;
            continue;
        }
        if (cloneFloor == exitFloor)
        {
            if (exitPos < clonePos && direction == "RIGHT")
            {
                cout << "BLOCK" << endl;
                continue;
            }
            if (exitPos > clonePos && direction == "LEFT")
            {
                cout << "BLOCK" << endl;
                continue;
            }
            cout << "WAIT" << endl;
            continue;
        }
        if (a[cloneFloor] < clonePos && direction == "RIGHT")
        {
            cout << "BLOCK" << endl;
            continue;
        }
        if (a[cloneFloor] > clonePos && direction == "LEFT")
        {
            cout << "BLOCK" << endl;
            continue;
        }
        cout << "WAIT" << endl;
        
        
        
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        //cout << "WAIT" << endl; // action: WAIT or BLOCK
    }
}