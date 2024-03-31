#include "sese/config/json/JsonUtil.h"
#include "sese/config/json/Marco.h"
#include "sese/io/InputBufferWrapper.h"
#include "sese/record/LogHelper.h"
#include "sese/util/Initializer.h"

using namespace sese::json;

int main(int argc, char **argv) {
    sese::initCore(argc, argv);
    const char content[]{
            "{"
            "   \"name\": \"example\","
            "   \"id\": 114514"
            "}"
    };
    auto input = std::make_shared<sese::io::InputBufferWrapper>(content, sizeof(content));
    auto object = JsonUtil::deserialize(input, 3);

    SESE_JSON_GET_STRING(name, object, "name", "undef");
    SESE_JSON_GET_INTEGER(id, object, "id", 0);

    sese::record::LogHelper::i(
            "name: %s, id %lld",
            name.c_str(),
            id
    );

    return 0;
}

//int main() {
//    const char content[]{
//            "{"
//            "   \"name\": \"example\","
//            "   \"id\": 114514"
//            "}"
//    };
//    auto input = std::make_shared<sese::InputBufferWrapper>(content, sizeof(content));
//
//    auto object = JsonUtil::deserialize(input, 3);
//    auto nameObject = object->getDataAs<BasicData>("name");
//    auto idObject = object->getDataAs<BasicData>("id");
//
//    sese::record::LogHelper::i(
//            "name: %s, id %lld",
//            nameObject->getDataAs<std::string>("undef").c_str(),
//            idObject->getDataAs<int64_t>(0)
//    );
//
//    return 0;
//}