//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <fstream>

bool isCreatedFiles = false;
std::filesystem::path uniqueFile;
std::filesystem::path uniquePath;

void createFiles() {
    if (!isCreatedFiles) {
        std::filesystem::path tempPath = std::filesystem::temp_directory_path();
        std::string tempStr = tempPath.native();
        size_t maxLength = 0;
        for (const auto &entry: std::filesystem::directory_iterator(tempStr)) {
            std::string file = entry.path().filename();
            if (file.size() > maxLength) {
                maxLength = file.size();
            }
        }
        std::string uniqueStr = "/";
        for (size_t i = 0; i < maxLength + 1; ++i) {
            uniqueStr += "o";
        }
        std::filesystem::path uniqueName = uniqueStr;
        std::cout << uniqueName << '\n';
        uniquePath = tempStr + uniqueName.native();
        std::filesystem::path uniqueDir = uniquePath.native() + "/dir";
        uniqueFile = uniquePath.native() + "/file.txt";
        std::filesystem::create_directories(uniqueDir);
        std::ofstream file(uniqueFile);
        isCreatedFiles = true;
    }
}

TEST(Test02, test1a) {
    try {
        auto error = GetTree("Hell world", true);
        ASSERT_EQ(false, true);
    }
    catch(...) {}
}

TEST(Test02, test1b) {
    createFiles();
    try{
        auto error = GetTree(uniqueFile, false);
        ASSERT_EQ(false, true);
    } catch(...) {}
}

TEST(Test02, test1c) {
    FileNode notEmpty = GetTree(uniquePath, false);
    FileNode empty = GetTree(uniquePath, true);
    ASSERT_EQ(notEmpty == empty, false);
}

TEST(Test02, test1d) {
    FileNode notEmpty = GetTree(uniquePath, false);
    FilterEmptyNodes(notEmpty, uniquePath);
}