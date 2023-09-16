#include "sese/convert/Base64Converter.h"
#include "sese/io/ConsoleOutputStream.h"
#include "sese/io/InputBufferWrapper.h"

int main() {
    auto input = sese::io::InputBufferWrapper("Hello", 5);
    auto console = sese::io::ConsoleOutputStream();
    sese::Base64Converter::encode(&input, &console);
    return 0;
}