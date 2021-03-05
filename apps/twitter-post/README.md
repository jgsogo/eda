How to post a tweet
===================

Twitter is one of the most popular social networks out there, being there
is a must for many companies. **Be there or you don't exist**.

It's really easy to publish a new status programatically using quite
common and robust libraries, even in C++! In this example we show how
to do it with `libcurl` and a couple of libraries we need for the 
authentication and JSON parsing, `liboauth` and `jansson`.

We will use CMake as our build system for convenience.

#### **`CMakeLists.txt`**
```cmake
cmake_minimum_required(VERSION 3.1)

project(TwPostImage CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(libcurl)
find_package(liboauth)
find_package(jansson)

add_executable(tw-post-image main.cpp)
target_link_libraries(tw-post-image PRIVATE CURL::CURL jansson::jansson liboauth::liboauth)
```

#### **`main.cpp` (only message)**
```cpp

#include <iostream>
#include <sstream>
#include <string>

#include <curl/curl.h>
#include <oauth.h>

int main() {
    const char* api_key = std::getenv("TWITTER_API_KEY");
    const char* api_secret_key = std::getenv("TWITTER_API_SECRET_KEY");
    const char* access_token = std::getenv("TWITTER_ACCESS_TOKEN");
    const char* access_token_secret = std::getenv("TWITTER_ACCESS_TOKEN_SECRET");

    std::cout << "TWITTER_API_KEY: '" << api_key << "'\n";
    std::cout << "TWITTER_ACCESS_TOKEN: '" << access_token << "'\n";

    const std::string message = "This is a test message";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    auto curl = curl_easy_init();

    std::ostringstream os;
    os << "https://api.twitter.com/1.1/statuses/update.json?status=" << curl_easy_escape(curl, message.c_str(), message.size());

    auto r = oauth_sign_url2(os.str().c_str(), nullptr, OA_HMAC, "POST", api_key, api_secret_key, access_token, access_token_secret);
    curl_easy_setopt(curl, CURLOPT_URL, r);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Console client");
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);

    auto status = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}
```

#### **`main.cpp` (message + photo)**
```cpp

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include <sys/stat.h>
#include <curl/curl.h>
#include <oauth.h>
#include "jansson.h"


const char* api_key = std::getenv("TWITTER_API_KEY");
const char* api_secret_key = std::getenv("TWITTER_API_SECRET_KEY");
const char* access_token = std::getenv("TWITTER_ACCESS_TOKEN");
const char* access_token_secret = std::getenv("TWITTER_ACCESS_TOKEN_SECRET");

std::string post_image(const char* image);
int post_message(std::string message, std::string media_id_string);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Pass a path to an image (or use default)\n"; 
        //return -1;
    }
    const char* image = (argc >= 2) ? argv[1] : "image.png";
    std::cout << "Will post image at " << image << "\n";

    std::cout << "TWITTER_API_KEY: '" << api_key << "'\n";
    //std::cout << "TWITTER_API_SECRET_KEY: '" << api_secret_key << "'\n";
    std::cout << "TWITTER_ACCESS_TOKEN: '" << access_token << "'\n";
    //std::cout << "TWITTER_ACCESS_TOKEN_SECRET: '" << access_token_secret << "'\n";
    
    
    const std::string message = "This is a test message";

    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    auto media_id_string = post_image(image);
    post_message(message, media_id_string);
    curl_global_cleanup();
}

namespace internals {

    constexpr int BUFFER_SIZE = 256 * 1024;  /* 256 KB */

    struct write_result {
        char *data;
        int pos;
    };

    static size_t write_response(void* ptr, size_t size, size_t nmemb, void* stream) {
        struct write_result *result = (struct write_result *) stream;

        if (result->pos + size * nmemb >= BUFFER_SIZE - 1) {
            fprintf(stderr, "error: too small buffer\n");
            return 0;
        }

        memcpy(result->data + result->pos, ptr, size * nmemb);
        result->pos += size * nmemb;

        return size * nmemb;
    }
}

std::string post_image(const char* image) {
    auto curl = curl_easy_init();

    auto form = curl_mime_init(curl);
    auto field = curl_mime_addpart(form);
    curl_mime_name(field, "media");
    curl_mime_filedata(field, image);
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

    std::ostringstream os;
    os << "https://upload.twitter.com/1.1/media/upload.json?media_category=tweet_image&media=@" << image;

    auto r = oauth_sign_url2(os.str().c_str(), nullptr, OA_HMAC, "POST", api_key, api_secret_key, access_token, access_token_secret);
    curl_easy_setopt(curl, CURLOPT_URL, r);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Console client");
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);

    struct internals::write_result write_result = {
                .data = (char*)malloc(internals::BUFFER_SIZE),
                .pos = 0
        };
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, internals::write_response);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &write_result);
    auto status = curl_easy_perform(curl);
    write_result.data[write_result.pos] = '\0';

    // Parse JSON
    json_error_t error;
    json_t* root = json_loads(write_result.data, 0, &error);
    free(write_result.data);

    json_t* id_str = json_object_get(root, "media_id_string");
    std::string media_id_string = json_string_value(id_str);

    std::cout << "Status: " << write_result.data << "\n";
    std::cout << "std::string media_id_string: " << media_id_string << "\n";
    //std::cout << curl_easy_strerror(status) << "\n";
    json_decref(root);
    curl_easy_cleanup(curl);
    return media_id_string;
}


int post_message(std::string message, std::string media_id_string) {
    auto curl = curl_easy_init();

    std::ostringstream os;
    os << "https://api.twitter.com/1.1/statuses/update.json?status=" << curl_easy_escape(curl, message.c_str(), message.size());
    os << "&media_ids=" << media_id_string;

    auto r = oauth_sign_url2(os.str().c_str(), nullptr, OA_HMAC, "POST", api_key, api_secret_key, access_token, access_token_secret);
    curl_easy_setopt(curl, CURLOPT_URL, r);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Console client");
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);

    struct internals::write_result write_result = {
        .data = (char*)malloc(internals::BUFFER_SIZE),
        .pos = 0
    };
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, internals::write_response);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &write_result);
    auto status = curl_easy_perform(curl);

    // Parse JSON
    json_error_t error;
    json_t* root = json_loads(write_result.data, 0, &error);
    free(write_result.data);

    json_t* id_str = json_object_get(root, "id_str");
    std::string id_tweet = json_string_value(id_str);

    std::ofstream out("output.txt");
    out << id_tweet;
    out.close();

    json_decref(root);
    
    curl_easy_cleanup(curl);
    return 0;
}
```

And this is all you need. Happy coding!

----

```
mkdir build && cd build
conan install .. --build missing
cmake .. -DCMAKE_MODULE_PATH=$(pwd)
cmake --build .
source ../secret.env && ./tw-post
```
