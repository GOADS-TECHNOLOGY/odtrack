#ifndef FPPAPI_H
#define FPPAPI_H

#include <string>
#include <atomic>

extern std::atomic<bool> stop_api_thread;

class FppApi
{
public:
    explicit FppApi(const std::string &base_url = "http://127.0.0.1");

    std::string getSystemStatus();
    std::tuple<int, std::string, int, std::string> getSystemStatusDetails();

private:
    std::string base_url_;
    static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
    std::string performGetRequest(const std::string &url);
};

#endif // FPPAPI_H