#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_get(http_request request) {
    try {
        // Set cache-control header to disable caching
        request.headers().set_cache_control(L"no-cache");

        // Create a JSON response with the string "Hello, World!"
        json::value response;
        response[U("message")] = json::value::string(U("Hello, World!"));

        // Send the JSON response
        request.reply(status_codes::OK, response);
    } catch (const std::exception &e) {
        std::cerr << "Error handling request: " << e.what() << std::endl;
        request.reply(status_codes::InternalError, "Internal Server Error");
    }
}

int main() {
    http_listener listener(L"http://localhost:3000/homepage");
    listener.support(methods::GET, handle_get);

    try {
        listener.open().wait();
        std::cout << "Server is listening..." << std::endl;

        // Wait for user input to stop the server
        std::cout << "Press Enter to exit." << std::endl;
        std::string line;
        std::getline(std::cin, line);

        listener.close().wait();
        std::cout << "Server stopped." << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
    