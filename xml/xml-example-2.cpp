#include "sese/config/xml/XmlUtil.h"
#include "sese/util/ConsoleOutputStream.h"

using namespace sese::xml;

int main() {
    auto object = std::make_shared<Element>("config");

    auto profile = std::make_shared<Element>("profile");
    object->addElement(profile);

    auto address = std::make_shared<Element>("address");
    address->setAttribute("type", "ipv4");
    address->setValue("192.168.3.1");
    profile->addElement(address);

    auto port = std::make_shared<Element>("port");
    port->setValue("443");
    profile->addElement(port);

    auto output = std::make_shared<sese::ConsoleOutputStream>();
    XmlUtil::serialize(object, output);

    return 0;
}