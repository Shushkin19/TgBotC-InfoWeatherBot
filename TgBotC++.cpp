

#include <tgbot/tgbot.h>
#include<curl/curl.h>
#include<nlohmann/json.hpp>
#include<iostream>
#include"InfoOut.h"
#include<thread>
#include<chrono>
#include"MyFuncBot.h"
#include"ParseJson.h"

#pragma warning(disable: 4996)

using namespace TgBot;

using json = nlohmann::json;

int main() {
   
    CURL* curl;
    std::string readBuffer;
    std::string Valute;
    InfoOut io;
    
    //std::time_t t = std::time(0);
    //std::tm* now = localtime(&t);

    TgBot::Bot bot("token");

    bot.getApi().deleteWebhook();


    bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
        });



      bot.getEvents().onCommand("launch", [&bot, &io, &curl, &readBuffer,&Valute](TgBot::Message::Ptr message) {
          while (1) {
              std::time_t t = std::time(0);
              std::tm* now = localtime(&t);
              //запускаю бесконечный цикл, который считывает время и с помощью ифов выполняет разные отправки сообщений

              if (now->tm_hour == 21&& now->tm_min == 45 && now->tm_sec == 0) { // каждый день в 13 часов 39 секунд приходит прогноз погоды на данный момент

                  WeatherBuff(readBuffer, curl);

                  InfoOut io(readBuffer, readBuffer.length());

                  FinanceTodayBuff(Valute, curl);

                  ParseJson Val(Valute);

                 
                  
                  bot.getApi().sendMessage(message->chat->id,u8"Погода сейчас:\n\nТемпература:  " + std::to_string(io.tempnow()) + " 'C" +
                      u8"\n\nВалюта:"+"\nEUR: " +
                      std::to_string(Val.ValueEUR()) +
                      "\nUSD: " + std::to_string(Val.ValueUSD()));
              }

              else if (now->tm_hour ==21 && now->tm_min == 45 && now->tm_sec == 10) {//Утренний прогноз
                  WeatherFutureTodayBuff(readBuffer, curl);
                  ParseJson pj(readBuffer);
                  FinanceTodayBuff(Valute, curl);
                  ParseJson Val(Valute);
                  bot.getApi().sendMessage(message->chat->id, u8"Погода на сегодня:\n\nТемпература:\n Макс: " + std::to_string(pj.tempmaxday()) + " 'C"
                      u8"\n Мин: " + std::to_string(pj.tempminday()) +" 'C" + u8"\n\nВалюта:"+"\nEUR: " + std::to_string(Val.ValueEUR()) +
                      "\nUSD: " + std::to_string(Val.ValueUSD()));
                  
              }

              else if (now->tm_hour == 21 && now->tm_min == 45 && now->tm_sec == 20) {//Прогноз на завтра
                  WeatherFutureTomorrowBuff(readBuffer, curl);
                  ParseJson pj(readBuffer);
                  FinanceTodayBuff(Valute, curl);
                  ParseJson Val(Valute);
                  bot.getApi().sendMessage(message->chat->id, u8"Погода на завтра:\n\nТемпература:\n Макс: " + std::to_string(pj.tempmaxday()) + " 'C"
                      u8"\nМин: " + std::to_string(pj.tempminday()) + " 'C"+ u8"\n\nВалюта:" +"\n\nEUR: " + std::to_string(Val.ValueEUR()) +
                      "\nUSD: " + std::to_string(Val.ValueUSD()));
                  
              }
          }
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
    }

    return 0;
}