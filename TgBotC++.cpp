

//#include <tgbot/tgbot.h>
#include<curl/curl.h>
#include<json/json.h>
#include<iostream>
#include"InfoOut.h"

//using namespace TgBot;



 size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl = curl_easy_init();
    std::string readBuffer;
        readBuffer.clear();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openweathermap.org/data/2.5/weather?q=Kolpino&appid=8fb3a19a8ce1766a1340546d7de4973e");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
       CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        std::cout << "\n\n\n";

        std::cout << readBuffer;

    }
    //char NoSTDStringArray[1024] = { 0 };
    //for (int i = 0; i < readBuffer.length(); i++) {
    //    NoSTDStringArray[i] = readBuffer[i];
    //}
    //int len = readBuffer.length();
    InfoOut io(readBuffer,readBuffer.length());
  

   std::cout << "\n\n\n" <<io.fells_like();
   std::cout << "\n\n\n" << io.pressure();
   std::cout << "\n\n\n" << io.tempmin();


     /* TgBot::Bot bot("5556000193:AAEnA30U_a6E5vbZ8Fh0se2VsDSRp8fTVL4");

    
  

    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hello, " + message->chat->firstName + ".\nIt's weather ShushaBot!\n");
        });
    
   

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
        });


    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    }
    catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }*/
    
    return 0;
}