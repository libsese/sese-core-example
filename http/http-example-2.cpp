#include <sese/record/Marco.h>
#include <sese/util/Initializer.h>
#include <sese/service/http/HttpClient_V1.h>
#include <sese/io/File.h>

using sese::Initializer;
using sese::service::v1::HttpClient;
using sese::service::v1::HttpClientHandle;

int main() {
    Initializer::getInitializer();

    HttpClient client;
    if (!client.init()) {
        SESE_WARN("failed to client.init()");
        return -1;
    }

    {
        auto file = sese::io::File::create("cn_bing_com_index.html", BINARY_BOTH_CREATE_TRUNC);
        auto handle = HttpClientHandle::create("https://cn.bing.com/");
        handle->setReadResponseBodyCallback([&file](void *buffer, size_t length){
            file->write(buffer, length);
        });

        auto future = client.post(handle);
        auto status = future.get();
        if (status == HttpClientHandle::RequestStatus::Succeeded) {
            SESE_INFO("request succeeded");
        }
        file->close();


        handle->setUrl("/home");
        handle->setReadResponseBodyCallback({});
        future = client.post(handle);
        status = future.get();
        if (status == HttpClientHandle::RequestStatus::Succeeded) {
            SESE_INFO("request succeeded");
        }

        client.shutdown();
    }
}