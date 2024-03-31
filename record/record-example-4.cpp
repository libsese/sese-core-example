#include "sese/record/Marco.h"
#include "sese/util/Initializer.h"

int main(int argc, char **argv) {
    sese::initCore(argc, argv);
    SESE_DEBUG("Hello World");
    SESE_INFO("STRING: %s", "Hello");
    SESE_WARN("NUMBER: %d", 1024);
    SESE_ERROR("BOOL: %s", true ? "true" : "false");
}