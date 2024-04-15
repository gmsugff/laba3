#include <iostream>
#include <YaScheduleApp.h>
#include <locale>

std::string OW_API_KEY = "e7c0bce5516c376f0d980ddc956bb225";
std::string YA_API_KEY = "ec846f28-142d-4543-aba7-ec9a3195a6ff";


int main() {
	std::locale::global(std::locale("ru_RU.UTF-8"));
	setlocale(LC_ALL, "RUS");
	std::cout << "Ââåäèòå ïóíêò îòïðàâëåíèÿ: ";
	std::string cityFrom; std::cin >> cityFrom;
	std::cout << "Ââåäèòå ïóíêò íàçíà÷åíèÿ: ";
	std::string cityTo; std::cin >> cityTo;
	YaScheduleApp* app = new YaScheduleApp(OW_API_KEY, YA_API_KEY, cityFrom, cityTo);
	std::cout << app->getScheduleBetweenCities();
	std::string request = this->yaScheduleRequest;
		 request += "ipkey" + this->yaScheduleRequest;
		 request += "&from=" = this->getCityCode(this ->getLatLon(this->cityFrom));
		 request += "&to=" +this->getCityCode(this ->getLatLon(this->cityTo));
		 json result = this->makeRequest(this->yandexSchedullelient, request);
		 std::map <std::string, std::string> raceTitle;
		 std::map <std::string, std::string> raceNember;
		 std::map <std::string, std::string> transportType;
		 std::map <std::string, std::string> code;
		 std::map <std::string, std::string> uid; 
		 std::map <std::string, std::string> end_time;
		 std::map <std::string, std::string> begin_time;
		 std::map <std::string, std::string> has_transfers;
		 std::map <std::string, std::string> currency;
		 std::map <std::string, std::string> price
		
		 for (int i = 0; i < result["segments"].size(); i++) {
			 std::vector<std::map<std::string, std::string>>race{};
			 raceTitle["Race Title"] = result["segments"][i]["thread"]["title"].get<std::string>{};
			 raceNember["Race Nember"] = result["segments"][i]["thread"]["number"].get<std::string>{};
			 transportType["Transport Type"] = result["segments"][i]["for"]["transport_type"].get<std::string>{};
			 code["code"] = result["segments"][i]["for"]["code"].get<std::string>{};
			 uid["uid"] = result["segments"][i]["thread"]["uid"].get<std::string>{};
			 end_time["end time"] = result["segments"][i]["thread"]["end_time"].get<std::string>{};
			 begin_time[" begin time"] = result["segments"][i]["thread"]["begin_time"].get<std::string>{};
			 has_transfers[" has transfers "] = result["segments"][i][to"]["has_transfers"].get<std::string>{};
		     currency[" begin time"] = result["places"][i]["currency"].get<std::string>{};
			 price[" price"] = result["places"][i]["price"].get<std::string>{};
			 race.push_back(raceTitle);
			 race.push_back(raceNember);
			 race.push_back(transportType);
			 race.push_back(code);
			 race.push_back(uid);
			 race.push_back(end_time);
			 race.push_back(begin_time);
			 race.push_back(has_transfers);
			 race.push_back(currency);
			 race.push_back(price);
			 this->schedule.push_back(race);
		 }
	return 0;
}
