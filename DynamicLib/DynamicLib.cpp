#include <string>

using namespace std;

extern "C" __declspec(dllexport) bool contains_all_chars(const char* str, const char* chars) {
    string s(str);
    for (const char* c = chars; *c != '\0'; ++c) {
        if (s.find(*c) == string::npos) {
            return false;
        }
    }
    return true;
}