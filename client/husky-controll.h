#ifndef __controller_h_
#define __controller_h_

#include <string>
#include "json.hpp"
#include "cpr/cpr.h"


namespace control {

char * ip;

void controlInit( char * initIp) {
    ip = initIp;
}

bool postCommand(char * command) {
    nlohmann::json my_json = nlohmann::json::object {
                {"Command", command}
        };
    auto r = cpr::Post(cpr::Url{ip},
                   cpr::Body{"{ 'Command' : '{%s}' }", command},
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