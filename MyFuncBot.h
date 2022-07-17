#pragma once
#include<curl/curl.h>
#include<string>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

void WeatherBuff(std::string& readBuffer, CURL*& curl);

void FinanceTodayBuff(std::string& readBuffer, CURL*& curl);

void  WeatherFutureTodayBuff(std::string& readBuffer, CURL*& curl);

void WeatherFutureTomorrowBuff(std::string& readBuffer, CURL*& curl);

//void rcout(char* string)
//
//{
//	char new_string[255];
//	CharToOem(string, new_string);
//	std::cout << new_string;
//}
