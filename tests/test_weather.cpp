#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"
#include "../my_code/date.h"

using namespace std;

int main() {
    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));

    string filenm;
    cout << "Input the name of the new readings file:\n";
    cin >> filenm;

    ifstream rfile(filenm);
    while (!rfile) {
        cout << "Could not read input file: " << filenm << endl;
		cout << "Input the name of the new readings file:\n";
    }
    int m, d, y;
    double temp, hum, ws;
    while (rfile >> m >> d >> y >> temp >> hum >> ws) {
        WReading wr = WReading(Date(d, m, y), temp, hum, ws);
        irkutsk.add_reading(wr);
    }
    rfile.close();

    cout << irkutsk << endl;
}
