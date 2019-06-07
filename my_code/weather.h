#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);


class Date {
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
 public:
    Date(int d, int m, int y);
 private:
     int day;
     int month;
     int year;
};


class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:
    WReading(Date dt, double temp, double hum, double ws) :
        date(dt), temperature(temp), humidity(hum), windspeed(ws)
    {
    }

 private:
    Date date;
    double temperature;  // stored temp in C
    double humidity;
    double windspeed;
};


const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
    // << should output name, rating, and use the GPS << to output my_loc
    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
 public:
    Weather(std::string nm, GPS loc);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
 private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};


#endif
