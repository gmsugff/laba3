#include <YaScheduleApp.h>


using json = nlohmann::json;


YaScheduleApp::YaScheduleApp(std::string openWeatherApiKey, std::string yaScheduleApiKey,
	std::string cityFrom, std::string cityTo) {
	this->openWeatherClient = new httplib::Client("http://api.openweathermap.org");
	this->yandexScheduleClient = new httplib::Client("http://api.rasp.yandex.net");
	this->cityFrom = cityFrom;
	this->cityTo = cityTo;
	this->openWeatherApiKey = openWeatherApiKey;
	this->yaScheduleApiKey = yaScheduleApiKey;
}


json YaScheduleApp::makeRequest(httplib::Client* client, std::string request) {
	if (auto response = client->Get(request)) {
		if (response->status == 200) {
			return json::parse(response->body);
		}
		else {
			std::cout << "Bad request " << response->status << std::endl;
		}
	}
	return *new json;
}


std::vector <std::string> YaScheduleApp::getLatLon(std::string city) {
	std::string request = this->openWeatherRequest;
	request += "q=" + city;
	request += "&appid=" + this->openWeatherApiKey;
	json result = this->makeRequest(this->openWeatherClient, request);
	std::vector <std::string> latLon = { to_string(result["coord"]["lon"]), to_string(result["coord"]["lat"])};
	return latLon;
}


std::string YaScheduleApp::getCityCode(std::vector <std::string> latLon) {
	std::string request = this->yaCityCodeRequest;
	request += "apikey=" + this->yaScheduleApiKey;
	request += "&lat=" + latLon[1];
	request += "&lng=" + latLon[0];
	std::string code = this->makeRequest(this->yandexScheduleClient, request)["code"].get<std::string>();
	return code;
}


json YaScheduleApp::getScheduleBetweenCities() {
	std::string request = this->yaScheduleRequest;
	request += "apikey=" + this->yaScheduleApiKey;
	request += "&from=" + this->getCityCode(this->getLatLon(this->cityFrom));
	request += "&to=" + this->getCityCode(this->getLatLon(this->cityTo));
	return this->makeRequest(this->yandexScheduleClient, request);
}