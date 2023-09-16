#include "sese/convert/Base64Converter.h"
#include "sese/io/ConsoleOutputStream.h"
#include "sese/io/InputBufferWrapper.h"

int main() {
    auto input = sese::io::InputBufferWrapper("SGVsbG8=", 8);
    auto console = sese::io::ConsoleOutputStream();
    sese::Base64Converter::decode(&input, &console);
    return 0;
}