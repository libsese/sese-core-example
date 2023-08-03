#include <sese/config/yaml/YamlUtil.h>
#include <sese/config/yaml/Marco.h>
#include <sese/util/InputBufferWrapper.h>
#include <sese/record/Marco.h>

int main () {
    const char *str = "root:\n"
                      "  string: \"Hello\"\n"
                      "  int: 90\n"
                      "  bool: yes";
    auto input = sese::InputBufferWrapper(str, strlen(str));
    auto object = std::dynamic_pointer_cast<sese::yaml::ObjectData>(sese::yaml::YamlUtil::deserialize(&input, 3));
    auto root = std::dynamic_pointer_cast<sese::yaml::ObjectData>(object->get("root"));

    SESE_YAML_GET_STRING(valueStr, root, "string", "undef");
    SESE_YAML_GET_INTEGER(valueInt, root, "int", 0);
    SESE_YAML_GET_BOOLEAN(valueBool, root, "bool", false);

    SESE_INFO("str  - %s", valueStr.c_str());
    SESE_INFO("int  - %d", (int) valueInt);
    SESE_INFO("bool - %s", valueBool ? "true" : "false");
}