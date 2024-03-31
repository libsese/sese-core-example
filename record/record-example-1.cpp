#include "sese/record/LogHelper.h"
#include "sese/util/Initializer.h"

constexpr char str[] = "Hello World";

int main(int argc, char **argv) {
    sese::initCore(argc, argv);
    sese::record::LogHelper::d("Hello World");
    sese::record::LogHelper::i("STRING: %s", str);
    sese::record::LogHelper::w("NUMBER: %d", 1024);
    sese::record::LogHelper::e("BOOL: %s", true ? "true" : "false");
    return 0;
}