#include <iostream>
#include <string>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include <typeinfo>

#include "Y.h"

using namespace std;

std::string OW_API_KEY = "e7c0bce5516c376f0d980ddc956bb225";
std::string YA_API_KEY = "ec846f28-142d-4543-aba7-ec9a3195a6ff";

int main()
{
    using json = nlohmann::json;
    setlocale(LC_ALL, "RUS");

    std::string cityNameFrom;
    std::cout << "Vvedite gorod: ";
    std::cin >> cityNameFrom;

    httplib::Client geoCli("http://api.openweathermap.org");
    
  

    json resultFrom;
    Y::From(geoCli, cityNameFrom,  OW_API_KEY , resultFrom);


    std::string lonFrom = to_string(resultFrom[0]["lon"]);
    std::string latFrom = to_string(resultFrom[0]["lat"]);

    std::string cityNameTo;
    std::cout << "Vvedite gorod naznacheniya: ";
    std::cin >> cityNameTo;
nlohmann::json resultTo;
  

    std::string lonTo = to_string(resultTo[0]["lon"]);
    std::string latTo = to_string(resultTo[0]["lat"]);

    std::cout << lonTo << " " << latTo << std::endl;
    Y::To(string cityNameTo, string OW_API_KEY, httplib::Client geoCl);

    httplib::Client cityCodeCli("http://api.rasp.yandex.net");

    json resultCodeFrom;

    void Y::CodeFrom(string YA_API_KEY, string lonFrom, string latFrom, string cityCodeCli);
    std::cout << scheduleResult;
}