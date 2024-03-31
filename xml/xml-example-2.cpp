#include "sese/config/xml/XmlUtil.h"
#include "sese/io/ConsoleOutputStream.h"
#include "sese/util/Initializer.h"

using namespace sese::xml;

int main(int argc, char **argv) {
    sese::initCore(argc, argv);
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

    auto output = sese::io::ConsoleOutputStream();
    XmlUtil::serialize(object, &output);

    return 0;
}