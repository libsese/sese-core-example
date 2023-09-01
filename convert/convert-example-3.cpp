#include <sese/convert/PercentConverter.h>
#include <sese/util/FixedBuilder.h>
#include <sese/record/Marco.h>

int main () {
    const char *string = "你好，2023";
    auto buffer1 = std::make_shared<sese::FixedBuilder>(128);
    sese::PercentConverter::encode(string, buffer1);
    buffer1->write("\0", 1);
    SESE_INFO("encode %s", buffer1->data());

    auto buffer2 = std::make_shared<sese::FixedBuilder>(128);
    sese::PercentConverter::decode(buffer1->data(), buffer2);
    buffer2->write("\0", 1);
    SESE_INFO("decode %s", buffer2->data());
    return 0;
}
