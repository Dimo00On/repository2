//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

TEST(Test02, test1) {
    char name[] = "/tmp/dirXXXXXX";
    char fileName[] = "/tmp/dirXXXXXX/fileXXXXXXX";
    char otherName[] = "/tmp/dirXXXXXX/dirXXXXXX";
    char* myPath = mkdtemp(name);
    for (int i = 0; i < 14; ++i) {
        otherName[i] = myPath[i];
        fileName[i] = myPath[i];
    }
    char* myOtherDir = mkdtemp(otherName);
    int fd;
    fd = mkstemp(fileName);
    try {
        auto error = GetTree("Hell world", true);
        ASSERT_EQ(false, true);
    }
    catch(...) {}
    try{
        auto error = GetTree(fileName, false);
        ASSERT_EQ(false, true);
    } catch(...) {}
    FileNode notEmpty = GetTree(myPath, false);
    FileNode empty = GetTree(myPath, true);
    ASSERT_EQ(notEmpty == empty, false);
    FilterEmptyNodes(notEmpty, myPath);
}