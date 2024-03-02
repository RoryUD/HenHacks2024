#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/uri.h> // Required for uri_builder
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_get(http_request request) {
    try {
        // Set cache-control header to disable caching
        request.headers().set_cache_control(L"no-cache");

        // Seed the random number generator with the current time
        srand(time(nullptr));

        // Generate a random number between 1 and 100
        int random_number = rand() % 100 + 1;

        // Create a JSON response with the random number
        json::value response;
        response[U("randomNumber")] = json::value::number(random_number);

        // Add CORS headers to allow requests from any origin
        web::http::http_response httpResponse(status_codes::OK);
        httpResponse.headers().add(U("Access-Control-Allow-Origin"), U("*")); // Allow requests from any origin
        httpResponse.headers().add(U("Access-Control-Allow-Methods"), U("GET")); // Allow only GET requests
        httpResponse.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type")); // Allow the Content-Type header

        // Set the JSON response body
        httpResponse.set_body(response);

        // Send the HTTP response
        request.reply(httpResponse);
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
