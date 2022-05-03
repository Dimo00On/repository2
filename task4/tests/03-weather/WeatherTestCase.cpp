//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(Test03, test1a) {
    WeatherMock weather;
    weather.GetTomorrowDiff("My amazing town");
}

TEST(Test03, test1b) {
    WeatherMock weather;
    weather.GetTomorrowDiff("My town");
}

TEST(Test03, test1c) {
    WeatherMock weather;
    weather.GetTomorrowDiff("MyTown");
}

TEST(Test03, test1d) {
    WeatherMock weather;
    weather.GetTomorrowDiff("Town");
}

TEST(Test03, test1e) {
    WeatherMock weather;
    std::string str = "I";
    weather.GetTomorrowDiff(str);
}

TEST(Test03, test2) {
    WeatherMock weather;
    weather.SetApiKey("TP2022");
}

TEST(Test03, test3) {
    WeatherMock weather;
    ASSERT_EQ(static_cast<int>(weather.FindDiffBetweenTwoCities("My town", "Ivanovo")), 0);
}

TEST(Test03, test4a) {
    WeatherMock weather;
    weather.GetDifferenceString("My town", "Ivanovo");
}

TEST(Test03, test4b) {
    WeatherMock weather;
    weather.GetDifferenceString("moscow", "Ivanovo");
}

TEST(Test04, test5) {
    try {
        WeatherMock weather;
        weather.GetResponseForCity("My town", cpr::Url{"what is it?"});
        ASSERT_EQ(false, true);
    } catch(...) {}
}