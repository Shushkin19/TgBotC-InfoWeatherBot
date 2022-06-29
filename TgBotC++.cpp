#include <stdio.h>

#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("5556000193:AAEnA30U_a6E5vbZ8Fh0se2VsDSRp8fTVL4");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "SevaLOx!");
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
    }

    return 0;
}