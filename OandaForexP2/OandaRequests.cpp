#include "OandaRequests.h"
#include <string>
#include <iostream>
#include <cpr/cpr.h>

    const std::string authToken = " Bearer 2ac5da17c64dbe1a3e25745bf929749d-5f1899e5d6fb2d67f9b6525fcf61dcd3";

    std::string getAccountId() {
        auto r = cpr::Get(cpr::Url{ "https://api-fxpractice.oanda.com/v3/accounts" },
            cpr::Header{ {"Authorization", authToken} });
        return r.text.substr(20, 20);
    }

    std::string getAccountInfo() {
        auto r = cpr::Get(cpr::Url{ "https://api-fxpractice.oanda.com/v3/accounts/"+getAccountId()},
            cpr::Header{ {"Authorization", authToken} });
        return r.text;
    }

    std::string getLastPricesForInstrument(std::string instrument, int count) {
        auto r = cpr::Get(cpr::Url{ "https://api-fxpractice.oanda.com/v3/instruments/" + 
                                instrument + "/candles?count=" + std::to_string(count) + "&price=M&granularity=S5" },
            cpr::Header{ {"Authorization", " Bearer 2ac5da17c64dbe1a3e25745bf929749d-5f1899e5d6fb2d67f9b6525fcf61dcd3"} });
        return r.text;
    }