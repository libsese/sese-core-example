#include "sese/thread/Thread.h"
#include "sese/record/LogHelper.h"
#include "sese/util/Initializer.h"

#include <functional>

void ThreadProc(const char *str) {
    sese::record::LogHelper::d("STRING: %s", str);
}

int main(int argc, char **argv) {
    sese::initCore(argc, argv);
    auto th1 = sese::Thread(std::bind(&ThreadProc, "Hello World"), "MyThread1");
    th1.start();
    th1.join();

    auto th2 = sese::Thread([]() -> void { ThreadProc("Hello World"); }, "MyThread2");
    th2.start();
    th2.join();

    return 0;
}