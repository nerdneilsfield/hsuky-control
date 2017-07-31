#ifndef __controller_h_
#define __controller_h_

#include <string>
#include "json.hpp"
#include "cpr/cpr.h"
#include <sstream>

namespace control {

char * ip;

void controlInit( char * initIp) {
    ip = initIp;
}

bool postCommand(std::string  command) {
    //nlohmann::json my_json = nlohmann::json::object{
    //            {"Command", command}
    //    };
    std::string postCommand = "{'Command' : " + command + "'}";
    auto r = cpr::Post(cpr::Url{ip},
                   cpr::Body{postCommand},
                   cpr::Header{{"Content-Type", "application/json"}});
    auto json = nlohmann::json::parse(r.text);
    bool result = json["result"];
    return result;

}

bool Forward() {
    return postCommand("nofo");
}

bool BackForward() {
    return postCommand("noba");
}

bool TurnLeft() {
    return postCommand("nole");
}

bool TurnRight() {
    return postCommand("nori");
}

bool HighSpeedForward() {
    return postCommand("hifo");
}

bool HighSpeedBackForward() {
    return postCommand("hiba");
}

bool HighSpeedTurnLeft() {
    return postCommand("hile");
}

bool HighSpeedTurnRight() {
    return postCommand("hiri");
}

}
#endif
