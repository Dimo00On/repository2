//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"

float WeatherMock::GetTemperature(const std::string& city) {
    return static_cast<float>(city.size());
}

float WeatherMock::GetTomorrowTemperature(const std::string& city) {
    return static_cast<float>(static_cast<int>(2 * city.size()) - 6);
}