#include <sese/config/yaml/YamlUtil.h>
#include <sese/config/yaml/Marco.h>
#include <sese/io/ConsoleOutputStream.h>
#include "sese/util/Initializer.h"

int main(int argc, char **argv) {
    sese::initCore(argc, argv);s
    auto object = std::make_shared<sese::yaml::ObjectData>();

    SESE_YAML_SET_STRING(object, "STR", "Hello");
    SESE_YAML_SET_BOOLEAN(object, "BOOL", true);
    SESE_YAML_SET_DOUBLE(object, "PI", 3.14);

    sese::io::ConsoleOutputStream output;
    sese::yaml::YamlUtil::serialize(object, &output);
}