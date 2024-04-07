#pragma once
class Y {

	void  From(httplib::Client geoCli ,  string cityNameFrom, string OW_API_KEY, json resultFrom);
	void To(string cityNameTo, string OW_API_KEY, httplib::Client geoCl);
	void CodeFrom(string YA_API_KEY, string lonFrom, string latFrom, string cityCodeCli);
};