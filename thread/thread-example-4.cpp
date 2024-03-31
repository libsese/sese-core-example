#include "sese/util/Initializer.h"
#include "sese/util/Util.h"
#include "sese/thread/Async.h"
#include "sese/record/Marco.h"

int main(int argc, char **argv) {
    sese::initCore(argc, argv);

    SESE_INFO("begin");
    {
        auto future = sese::async<std::string>([]() -> std::string {
            sese::sleep(1s);
            return "Hello, World";
        });
        SESE_INFO("result: %s", future.get().c_str());
    }
    {
        auto future = sese::asyncWithGlobalPool<std::string>([]() -> std::string{
            sese::sleep(1s);
            return "Bye";
        });
        SESE_INFO("result: %s", future.get().c_str());
    }

    return 0;
}