#include "sese/convert/Base64Converter.h"
#include "sese/util/ConsoleOutputStream.h"
#include "sese/util/InputBufferWrapper.h"

int main() {
    auto input = sese::InputBufferWrapper("Hello", 5);
    auto console = sese::ConsoleOutputStream();
    sese::Base64Converter::encode(&input, &console);
    return 0;
}