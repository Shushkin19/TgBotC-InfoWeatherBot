

#include <tgbot/tgbot.h>
#include<curl/curl.h>
#include<json/json.h>
#include<iostream>
#include"InfoOut.h"
#include<thread>
#include<chrono>
#include"MyFuncBot.h"


using namespace TgBot;



int main() {
    setlocale(LC_ALL, "ru");
    CURL* curl;
    std::string readBuffer;
    InfoOut io;
 
      TgBot::Bot bot("5556000193:AAEnA30U_a6E5vbZ8Fh0se2VsDSRp8fTVL4");
     
      bot.getEvents().onCommand("start", [&bot, &io, &curl, &readBuffer](TgBot::Message::Ptr message) {
          int bg = time(NULL);
          int sec = 10;
          int end = bg + sec;
          while (1) {
              bg = time(NULL);
              if (bg == end) {
                  end += sec;
                 WeatherBuff(readBuffer, curl);
                  InfoOut io(readBuffer, readBuffer.length());
                  bot.getApi().sendMessage(message->chat->id,
                      "Weather: " + io.mainweather() + "\nTempNow: " + std::to_string(io.tempnow()) +
                      "\nfeels_like: " + std::to_string(io.fells_like()) + "\nWind: " + std::to_string(io.wind()) +
                      "\nTempMax: " + std::to_string(io.tempmax()) + "\nPressure: " + std::to_string(io.pressure())); 
              }
          }
          });
   //Когда наступает определенное время флаг становится 1 и выполняется код, меняя флаг на ноль
   
   
  
    
     
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
    }
    
    return 0;
}