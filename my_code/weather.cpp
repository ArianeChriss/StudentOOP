#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

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