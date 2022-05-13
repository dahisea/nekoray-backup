#ifndef NEKORAY_VMESSBEAN_HPP
#define NEKORAY_VMESSBEAN_HPP

#include "fmt/AbstractBean.hpp"
#include "fmt/comm/V2RayStreamSettings.hpp"

namespace NekoRay::fmt {
    class VMessBean : public AbstractBean {
    public:
        QString uuid = "";
        int aid = 0;
        QString security = "auto";

        QSharedPointer<V2rayStreamSettings> stream = QSharedPointer<V2rayStreamSettings>(new V2rayStreamSettings());
        QString custom = "";

        VMessBean() : AbstractBean(0) {
            _add(new configItem("uuid", &uuid, itemType::string));
            _add(new configItem("aid", &aid, itemType::integer));
            _add(new configItem("security", &security, itemType::string));
            _add(new configItem("stream", dynamic_cast<JsonStore *>(stream.get()), itemType::jsonStore));
            _add(new configItem("custom", &custom, itemType::string));
        };

        QString DisplayType() override { return "VMess"; };

        CoreObjOutboundBuildResult BuildCoreObj() override;

        bool TryParseLink(const QString &link);

        QString ToShareLink() override ;
    };
}

#endif //NEKORAY_VMESSBEAN_HPP