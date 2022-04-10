//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(Test03, test1) {
    WeatherMock weather;
    weather.GetTomorrowDiff("My amazing town");
    weather.GetTomorrowDiff("My town");
    weather.GetTomorrowDiff("MyTown");
    weather.GetTomorrowDiff("Town");
    std::string str = "I";
    weather.GetTomorrowDiff(str);
    weather.SetApiKey("TP2022");
    ASSERT_EQ(static_cast<int>(weather.FindDiffBetweenTwoCities("My town", "Ivanovo")), 0);
    weather.GetDifferenceString("My town", "Ivanovo");
    weather.GetDifferenceString("moscow", "Ivanovo");
    try {
        weather.GetResponseForCity("My town", cpr::Url{"what is it?"});
        ASSERT_EQ(false, true);
    } catch(...) {}
}