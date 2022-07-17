#include "MyFuncBot.h"
#include<string>
#include<curl/curl.h>
#include<iostream>
#include<json/json.h>
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void WeatherBuff(std::string& readBuffer, CURL*& curl) {
    curl = curl_easy_init();
    if (curl) {
        readBuffer.clear();
        curl_easy_setopt(curl, CURLOPT_URL, "api");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
       // std::cout << readBuffer;
    }
}

void WeatherFutureTomorrowBuff(std::string& readBuffer, CURL*& curl) {
    curl = curl_easy_init();
    if (curl) {
        readBuffer.clear();
        curl_easy_setopt(curl, CURLOPT_URL, "api");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        // std::cout << readBuffer<<std::endl;
        
    }
}

void FinanceTodayBuff(std::string& readBuffer, CURL*& curl) {
    curl = curl_easy_init();
    if (curl) {
        readBuffer.clear();
        curl_easy_setopt(curl, CURLOPT_URL, "api");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        //std::cout << readBuffer << std::endl;
    }
}

void WeatherFutureTodayBuff(std::string& readBuffer, CURL*& curl) {
    curl = curl_easy_init();
    if (curl) {
        readBuffer.clear();
        curl_easy_setopt(curl, CURLOPT_URL, "api");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        // std::cout << readBuffer<<std::endl;
         
}