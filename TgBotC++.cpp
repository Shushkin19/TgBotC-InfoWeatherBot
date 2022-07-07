

#include <tgbot/tgbot.h>
#include<curl/curl.h>
#include<json/json.h>
#include<iostream>
#include"InfoOut.h"
#include<thread>
#include<chrono>
#include"MyFuncBot.h"
#pragma warning(disable: 4996)

using namespace TgBot;



int main() {
    setlocale(LC_ALL, "ru");
    CURL* curl;
    std::string readBuffer;
    InfoOut io;

    //std::time_t t = std::time(0);
    //std::tm* now = localtime(&t);
       
      TgBot::Bot bot("5556000193:AAEnA30U_a6E5vbZ8Fh0se2VsDSRp8fTVL4");
     
      bot.getApi().deleteWebhook();


      bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
          bot.getApi().sendMessage(message->chat->id, "Hi!");
          });




      //for (int i = 0; i < 60; i++) {
      //    std::time_t t = std::time(0);   // get time now
      //    std::tm* now = localtime(&t);
      //    // std::this_thread::sleep_for(std::chrono::seconds(1));
      //    if (i == now->tm_sec) {
      //        std::cout << "\ncool: " << i << "-i  sec: " << now->tm_sec << std::endl;
      //    }
      //    else {
      //        std::cout << "\nnot cool: " << i << "-i  sec: " << now->tm_sec << std::endl;
      //    }
      



      bot.getEvents().onCommand("star", [&bot, &io, &curl, &readBuffer](TgBot::Message::Ptr message) {
          while (1) {
              std::time_t t = std::time(0);
              std::tm* now = localtime(&t);
              //запускаю бесконечный цикл, который считывает время и с помощью ифов выполняет разные отправки сообщений

              if (now->tm_hour == 13 && now->tm_min == 00 && now->tm_sec == 39) { // каждый день в 13 часов 39 секунд приходит прогноз погоды на данный момент

                  WeatherBuff(readBuffer, curl);
                  InfoOut io(readBuffer, readBuffer.length());
                  bot.getApi().sendMessage(message->chat->id,
                      "Weather: " + io.mainweather() + "\nTempNow: " + std::to_string(io.tempnow()) +
                      "\nfeels_like: " + std::to_string(io.fells_like()) + "\nWind: " + std::to_string(io.wind()) +
                      "\nTempMax: " + std::to_string(io.tempmax()) + "\nPressure: " + std::to_string(io.pressure()));
                  std::this_thread::sleep_for(std::chrono::minutes(1));
              }
              else if (now->tm_hour == 7 && now->tm_min == 00 && now->tm_sec == 39) {//Утренний прогноз

              }
              else if (now->tm_hour == 22 && now->tm_min == 00 && now->tm_sec == 39) {//Прогноз на завтра

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

    /*try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());

        TgWebhookTcpServer webhookServer(8080, bot);

        printf("Server starting\n");
        bot.getApi().setWebhook(webhookUrl);
        webhookServer.start();
    }
    catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }*/
    return 0;
}