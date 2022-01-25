#pragma once

#include <string>

using namespace std;

string getMD5String(const unsigned char* in, const size_t length);
string getMD5String(const string& contentString);