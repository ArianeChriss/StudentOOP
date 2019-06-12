#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
	: width(w), height(h)
{
	filename = flnm;
	image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
	Image temp = Image(img2.width, img2.height, img2.filename);
	temp.image_buf = new char[img2.width * img2.height];
	temp.copy_fields(img2);
}

Image::~Image() {
	if (image_buf != nullptr) delete image_buf;
}

Image& Image::operator=(const Image& img2) {
	copy_fields(img2);
	return *this;
}

int Image::image_sz() {
	return width * height;
}


void Image::copy_fields(const Image& img2) {
	width = img2.width;
	height = img2.height;
	filename = img2.filename;
	for (int i = 0; i < image_sz(); ++i) {
		image_buf[i] = img2.image_buf[i];
	}
}


/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
string Image::display(std::string s) {
	return "Displaying image " + s;
}


/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}

string Weather::get_name() const {
    return station_nm;
}

int Weather::get_rating() const {
	return rating;
}

void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

double WReading::get_tempF() {
	return (temperature * C_TO_F) + 32;
}

/*double Weather::get_heat_index(WReading& wr) { // need temperature and humidity
	double heat = 1;
}

double Weather::get_wind_chill(WReading& wr) { // need temperature and wind speed
	double windchill = 35.74 + (0.6215 * wr.get_temp() ^ 0.16) - (35.75 * wr.get_windspeed()) + (0.4275 * wr.get_temp() * wr.get_windspeed() ^ 0.16);
	return windchill;
}*/



ostream & operator<<(ostream & os, const GPS & gps)
{
	os << "(" << gps.latitude << ", " << gps.longitude << ")\n";
	return os;
}

ostream & operator<<(ostream & os, const Weather & w)
{
	os << w.get_name() << "\n" << w.get_rating() << "\n" 
		<< w.my_loc << endl;
	return os;
}

ostream & operator<<(ostream & os, const WReading & wr) {
	os << wr.date << "\nTemperature: " << wr.temperature
		<< "\nHumidity: " << wr.humidity << "\nWindspeed: "
		<< wr.windspeed;
	return os;
}