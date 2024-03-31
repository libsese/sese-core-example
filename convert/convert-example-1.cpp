#include "sese/convert/Base64Converter.h"
#include "sese/io/ConsoleOutputStream.h"
#include "sese/io/InputBufferWrapper.h"
#include "sese/util/Initializer.h"

int main(int argc, char **argv) {
    sese::initCore(argc, argv);
    auto input = sese::io::InputBufferWrapper("Hello", 5);
    auto console = sese::io::ConsoleOutputStream();
    sese::Base64Converter::encode(&input, &console);
    return 0;
}