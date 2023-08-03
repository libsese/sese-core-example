#include <sese/config/yaml/YamlUtil.h>
#include <sese/config/yaml/Marco.h>
#include <sese/util/ConsoleOutputStream.h>

int main() {
    auto object = std::make_shared<sese::yaml::ObjectData>();

    SESE_YAML_SET_STRING(object, "STR", "Hello");
    SESE_YAML_SET_BOOLEAN(object, "BOOL", true);
    SESE_YAML_SET_DOUBLE(object, "PI", 3.14);

    sese::ConsoleOutputStream output;
    sese::yaml::YamlUtil::serialize(object, &output);
}