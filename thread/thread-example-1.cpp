#include "sese/thread/Thread.h"
#include "sese/record/LogHelper.h"
#include "sese/util/Initializer.h"

void ThreadProc() {
    sese::record::LogHelper::d("Hello World");
}

int main(int argc, char **argv) {
    sese::initCore(argc, argv);
    auto th1 = sese::Thread(ThreadProc, "MyThread");
    th1.start();
    th1.join();

    auto th2 = std::thread(ThreadProc);
    th2.join();

    ThreadProc();

    return 0;
}