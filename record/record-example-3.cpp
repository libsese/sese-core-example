#include "sese/record/LogHelper.h"
#include "sese/record/Logger.h"
#include "sese/record/BlockAppender.h"

const char str[] = "Hello World";

int main() {
    auto pLogger = sese::record::getLogger();
    auto appender = std::make_shared<sese::record::BlockAppender>(128);
    pLogger->addAppender(appender);

    sese::record::LogHelper logHelper;
    logHelper.debug("Hello World");
    logHelper.info("STRING: %s", str);
    logHelper.warn("NUMBER: %d", 1024);
    logHelper.error("BOOL: %s", true ? "true" : "false");
    return 0;
}