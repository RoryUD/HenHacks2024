#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_get(http_request request) {
    // Handle GET request
    json::value response;
    response[U("message")] = json::value::string(U("Hello, World!"));

    request.reply(status_codes::OK, response);
}

int main() {
    http_listener listener(L"http://localhost:8080/api");
    listener.support(methods::GET, handle_get);

    try {
        listener.open().wait();
        std::cout << "Server is listening..." << std::endl;
        while (true);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
