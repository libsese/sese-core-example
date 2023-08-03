#include "sese/record/LogHelper.h"

const char str[] = "Hello World";

int main() {
    sese::record::LogHelper logHelper;
    logHelper.debug("Hello World");
    logHelper.info("STRING: %s", str);
    logHelper.warn("NUMBER: %d", 1024);
    logHelper.error("BOOL: %s", true ? "true" : "false");
    return 0;
}