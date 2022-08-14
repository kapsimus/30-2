#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    cpr::Response r;
    std::string text, header;
    size_t begin, end;
    const char* h2Open = "<h2>";
    const char* h2Close = "</h2>";
    r = cpr::Get(cpr::Url("http://httpbin.org/#/Response_formats/get_html"), cpr::Header ({{"Accept", "text/html"}}));
    text = r.text;
    begin = text.find(h2Open,0) + 4;
    end = text.find(h2Close, begin);
    header = text.substr(begin, end - begin);
    std::cout << header << std::endl;
    return 0;
}
