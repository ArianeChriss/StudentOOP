#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include "date.h"

/*
 * This will be the base class for all types of images.
 * */
class Image {
public:
	Image(int w, int h, std::string flnm);
	// copy constructor:
	Image(const Image& img2);
	~Image();
	Image& operator=(const Image& img2);
	int image_sz();

	/*
	 * Setting `display() = 0` here makes this an abstract
	 * class that can't be implemented.
	 * */
	std::string display(std::string s);
	/*
	 * If we don't want virtual method lookup, we
	 * could just declare:
	 * void display();
	 * */

	int get_height() { return height; }
	int get_width() { return width; }

private:
	int width;
	int height;
	std::string filename;
	char* image_buf;
	void copy_fields(const Image& img2);
};

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:
    WReading(Date dt, double temp, double hum, double ws) :
        date(dt), temperature(temp), humidity(hum), windspeed(ws) {}
	int get_temp() { return temperature; }
	int get_humidity() { return humidity; }
	int get_windspeed() { return windspeed; }
	double get_tempF();
	double get_tempC() { return temperature; }

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

	// double get_heat_index(WReading& wr);
	// double get_wind_chill(WReading& wr);
 private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};


#endif
