#include "Y.h"

void Y::From(httplib::geoCli, string cityNameFrom, string OW_API_KEY, json resultFrom)
{
    std::string requestFrom = "/geo/1.0/direct?";
    requestFrom += "q=" + cityNameFrom;
    requestFrom += "&limit=" + '10';
    requestFrom += "&appid=" + OW_API_KEY;

    
    auto responseFrom = geoCli.Get(requestFrom);

    if (responseFrom) {
        if (responseFrom->status == 200) {
            resultFrom = json::parse(responseFrom->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }

    std::string lonFrom = to_string(resultFrom[0]["lon"]);
    std::string latFrom = to_string(resultFrom[0]["lat"]);

    std::cout << lonFrom << " " << latFrom << std::endl;

}

void Y::To(string cityNameTo, string OW_API_KEY, httplib::Client geoCl)
{
    std::string cityNameTo;
    std::cout << "Vvedite gorod naznacheniya: ";
    std::cin >> cityNameTo;

    std::string requestTo = "/geo/1.0/direct?";
    requestTo += "q=" + cityNameTo;
    requestTo += "&limit=" + '10';
    requestTo += "&appid=" + OW_API_KEY;

    nlohmann::json resultTo;

    if (auto responseTo = geoCli.Get(requestTo)) {
        if (responseTo->status == 200) {
            resultTo = nlohmann::json::parse(responseTo->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }

    std::string lonTo = to_string(resultTo[0]["lon"]);
    std::string latTo = to_string(resultTo[0]["lat"]);

    std::cout << lonTo << " " << latTo << std::endl;
}

void Y::CodeFrom(string YA_API_KEY, string lonFrom, string latFrom, string cityCodeCli)
{
    std::string cityCodeReqFrom = "/v3.0/nearest_settlement/?";
    cityCodeReqFrom += "apikey=" + YA_API_KEY;
    cityCodeReqFrom += "&lat=" + latFrom;
    cityCodeReqFrom += "&lng=" + lonFrom;

    if (auto responseCodeFrom = cityCodeCli.Get(cityCodeReqFrom)) {
        if (responseCodeFrom->status == 200) {
            resultCodeFrom = json::parse(responseCodeFrom->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }

    std::string codeFrom = resultCodeFrom["code"].get<std::string>();

    json resultCodeTo;

    std::string cityCodeReqTo = "/v3.0/nearest_settlement/?";
    cityCodeReqTo += "apikey=" + YA_API_KEY;
    cityCodeReqTo += "&lat=" + latTo;
    cityCodeReqTo += "&lng=" + lonTo;

    if (auto responseCodeTo = cityCodeCli.Get(cityCodeReqTo)) {
        if (responseCodeTo->status == 200) {
            resultCodeTo = json::parse(responseCodeTo->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }

    std::string codeTo = resultCodeTo["code"].get<std::string>();

    std::cout << codeTo << std::endl;

    json scheduleResult;


    std::string scheduleReq = "/v3.0/search/?";
    scheduleReq += "apikey=" + YA_API_KEY;
    scheduleReq += "&from=" + codeFrom;
    scheduleReq += "&to=" + codeTo;

    if (auto responseSchedule = cityCodeCli.Get(scheduleReq)) {
        if (responseSchedule->status == 200) {
            scheduleResult = json::parse(responseSchedule->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }

}
