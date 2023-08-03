#include "sese/record/Marco.h"

int main () {
    SESE_DEBUG("Hello World");
    SESE_INFO("STRING: %s", "Hello");
    SESE_WARN("NUMBER: %d", 1024);
    SESE_ERROR("BOOL: %s", true ? "true" : "false");
}