#include "sese/config/json/JsonUtil.h"
#include "sese/config/json/Marco.h"
#include "sese/util/ConsoleOutputStream.h"

using namespace sese::json;

int main() {
    auto object = std::make_shared<sese::json::ObjectData>();

    SESE_JSON_SET_STRING(object, "name", "example");
    SESE_JSON_SET_INTEGER(object, "id", 1919810);

    auto output = std::make_shared<sese::ConsoleOutputStream>();
    JsonUtil::serialize(object, output);

    return 0;
}

//int main() {
//    auto object = std::make_shared<sese::json::ObjectData>();
//
//    auto nameObject = std::make_shared<BasicData>();
//    nameObject->setDataAs<std::string>("example");
//
//    auto idObject = std::make_shared<BasicData>();
//    idObject->setDataAs<int64_t>(1919810);
//
//    object->set("name", nameObject);
//    object->set("id", idObject);
//
//    auto output = std::make_shared<sese::ConsoleOutputStream>();
//    JsonUtil::serialize(object, output);
//
//    return 0;
//}