#include <windows.h>
#include <string>

namespace Utils
{
    // convert UTF-8 string to wstring
    std::wstring utf8_to_wstring(const std::string& str) {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
        std::wstring wstr(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size_needed);
        return wstr;
    }

    // convert wstring to UTF-8 string
    std::string wstring_to_utf8(const std::wstring& str) {
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
        std::string utf8(size_needed, 0);
        WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, &utf8[0], size_needed, NULL, NULL);
        return utf8;
    }
}