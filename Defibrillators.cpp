#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct defibrillator
{
    int n;
    string name, address, phone;
    double lon, lat;
    defibrillator()
    {
        n = 0;
        name = address = phone = "";
        lon = lat = 0;
    }
};

double dis(double lonA, double latA, double lonB, double latB)
{
    double ret;
    double x, y;
    x = (lonB-lonA) * cos((latA+latB)/2);
    y = latB - latA;
    ret = sqrt(x*x+y*y)*6371;
    return ret;
}

double StrToNum(string s)
{
    bool flag = true;
    double pre = 1;
    double ans = 0;
    for (int i = 0; i < s.size(); i ++)
    {
        if (s[i] == ',')
        {
            flag = false;
            continue;
        }
        if (flag == true)
        {
            ans = ans*10 + s[i]-'0';
            continue;
        }
        else
        {
            pre = pre * 0.1;
            ans = ans + pre*(s[i]-'0');
            continue;
        }
    }
    return ans;
}

double lon = 0, lat = 0;
defibrillator a[10010];

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    lon = StrToNum(LON);
    //cout << lon << endl;
    
    string LAT;
    cin >> LAT; cin.ignore();
    lat = StrToNum(LAT);
    //cout << lat << endl;
    
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        string t = "";
        int count = 0;
        for (int j = 0; j < s.size(); j ++)
        {
            if (s[j] != ';')
            {
                t += s[j];
                if (j != s.size()-1)
                    continue;
            }
            count ++;
            //cout << t << endl;
            if (count == 1)
            {
                a[i].n = StrToNum(t);
            }
            else if (count == 2)
            {
                a[i].name = t;
            }
            else if (count == 3)
            {
                a[i].address = t;
            }
            else if (count == 4)
            {
                a[i].phone = t;
            }
            else if (count == 5)
            {
                a[i].lon = StrToNum(t);
            }
            else if (count == 6)
            {
                a[i].lat = StrToNum(t);
            }
            t = "";
        }
    }
    
    int ans = 0;
    double mindis = dis(lon, lat, a[0].lon, a[0].lat);
    for (int i = 1; i < N; i ++)
    {
        double now;
        now = dis(lon, lat, a[i].lon, a[i].lat);
        if (now < mindis)
        {
            mindis = now;
            ans = i;
        }
    }
    
    cout << a[ans].name << endl;
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    //cout << "answer" << endl;
}
















































