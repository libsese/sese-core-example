#include "sese/thread/ThreadPool.h"
#include "sese/record/LogHelper.h"
#include "sese/util/Initializer.h"

#include <functional>
#include <chrono>

using namespace std::chrono_literals;

void ThreadProc(const char *str) {
    sese::record::LogHelper::d("STRING: %s", str);
}

int main(int argc, char **argv) {
    sese::initCore(argc, argv);
    auto pool = sese::ThreadPool("MyThreadPool", 4);
    pool.postTask(std::bind(&ThreadProc, "Hello"));

    std::this_thread::sleep_for(100ms);
    pool.shutdown();
    return 0;
}