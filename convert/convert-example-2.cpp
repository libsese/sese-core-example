#include "sese/convert/Base64Converter.h"
#include "sese/util/ConsoleOutputStream.h"
#include "sese/util/InputBufferWrapper.h"

int main() {
    auto input = sese::InputBufferWrapper("SGVsbG8=", 8);
    auto console = sese::ConsoleOutputStream();
    sese::Base64Converter::decode(&input, &console);
    return 0;
}