#include "sese/config/xml/XmlUtil.h"
#include "sese/record/LogHelper.h"
#include "sese/io/InputBufferWrapper.h"
#include "sese/util/Initializer.h"

int main(int argc, char **argv) {
    sese::initCore(argc, argv);
    const char xml[]{
            "<root>\n"
            "    <person>\n"
            "        <name type=\"string\">foo</name>\n"
            "        <id type=\"integer\">10001</id>\n"
            "    </person>\n"
            "</root>"
    };
    auto input = std::make_shared<sese::io::InputBufferWrapper>(xml, sizeof(xml));

    auto object = sese::xml::XmlUtil::deserialize(input, 3);
    auto person = object->getElements()[0];
    auto name = person->getElements()[0]->getValue();
    auto nameType = person->getElements()[0]->getAttribute("type", "undef");
    auto id = person->getElements()[1]->getValue();
    auto idType = person->getElements()[1]->getAttribute("type", "undef");

    sese::record::LogHelper::i("value: %s, type: %s", name.c_str(), nameType.c_str());
    sese::record::LogHelper::i("value: %s, type: %s", id.c_str(), idType.c_str());

    return 0;
}