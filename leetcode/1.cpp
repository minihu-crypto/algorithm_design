#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    string programName(argv[0]);
    string in_str = programName + "In.txt", out_str = programName+"Out.txt";
    const char* IN_FILE = in_str.c_str();
    const char* OUT_FILE = out_str.c_str();
    freopen(IN_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    
    return 0;
}