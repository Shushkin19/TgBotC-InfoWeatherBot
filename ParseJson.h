#pragma once
#include<string>
#include<nlohmann/json.hpp>
class ParseJson
{
	nlohmann::json arr;
public:
	ParseJson() {
		arr = NULL;
	}
	ParseJson(std::string& a) {
		arr = nlohmann::json::parse(a);
	}
	int tempmaxday();
	int tempminday();
	double ValueEUR();
	std::string mainweather();
	double ValueUSD();
	friend void insertion_sort(int* arr, int n);
};

void insertion_sort(int* arr, int n);
	