//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMock : public Weather {
    float GetTemperature(const std::string& city) override;
    float GetTomorrowTemperature(const std::string& city) override;
};



