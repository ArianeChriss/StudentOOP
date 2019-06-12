#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"

using namespace std;

void get_wreadings(string filenm, Weather& w) {
    ifstream rfile(filenm);
    if (!rfile) {
        cout << "Could not read input file: " << filenm << endl;
        exit(1);
    }
    int m, d, y;
    double temp, hum, ws;
    while (rfile >> m >> d >> y >> temp >> hum >> ws) {
        WReading wr = WReading(Date(d, m, y), temp, hum, ws);
        w.add_reading(wr);
    }
    rfile.close();
}

void make_images1(Image& img1) {
    for (int i = 0; i < 100; i++) {
        Image img2 = Image(10, 10, "foo.txt");
        img2 = img1;
    }
}

void make_images2(Image& img1) {
    for (int i = 0; i < 100; i++) {
        Image img2 = img1;
    }
}


int main() {
    string fnm = "happy.gif!";
    Image img = Image(100, 100, fnm);
    for (int i = 1; i < 100; i++) {
        make_images1(img);
        make_images2(img);
    }
    exit(0);

    Date date1 = Date(1, 1, 2019);
    WReading test_temps = WReading(date1, 0, 50, 10);
    int wr_size = sizeof(test_temps);
    cout << "Size of a Date is " << sizeof(date1) << endl;
    cout << "Size of a WReading is " << wr_size << endl;

    double freezingF = test_temps.get_tempF();
    assert(freezingF == 32.0);
    test_temps = WReading(Date(1, 1, 2019), 100, 50, 10);
    freezingF = test_temps.get_tempF();
    assert(freezingF == 212.0);

    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));

    string filenm;
    cout << "Input the name of the new readings file:\n";
    cin >> filenm;

    get_wreadings(filenm, irkutsk);

//    cout << irkutsk << endl;
}
