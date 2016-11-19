/**
 * A library for Qt app
 *
 * LICENSE: The GNU Lesser General Public License, version 3.0
 *
 * @author      Akira Ohgaki <akiraohgaki@gmail.com>
 * @copyright   Akira Ohgaki
 * @license     https://opensource.org/licenses/LGPL-3.0  The GNU Lesser General Public License, version 3.0
 * @link        https://github.com/akiraohgaki/qtlibs
 */

#include "ocsapi.h"

#include <QXmlStreamReader>

#include "json.h"
#include "networkresource.h"

namespace qtlibs {

/**
 * OCS-API Specification
 * http://www.freedesktop.org/wiki/Specifications/open-collaboration-services/
 */

OcsApi::OcsApi(const QUrl &baseUrl, QObject *parent)
    : QObject(parent), baseUrl_(baseUrl)
{}

OcsApi::OcsApi(const OcsApi &other, QObject *parent)
    : QObject(parent)
{
    setBaseUrl(other.baseUrl());
}

OcsApi &OcsApi::operator =(const OcsApi &other)
{
    setBaseUrl(other.baseUrl());
    return *this;
}

QUrl OcsApi::baseUrl() const
{
    return baseUrl_;
}

void OcsApi::setBaseUrl(const QUrl &baseUrl)
{
    baseUrl_ = baseUrl;
}

QJsonObject OcsApi::fetchCategories()
{
    return QJsonObject();
}

QJsonArray OcsApi::fetchProvidersFile(const QUrl &url)
{
    QJsonArray providers;

    QXmlStreamReader reader(qtlibs::NetworkResource(url.url(), url, false).get()->readData());

    QStringList whitelist;
    whitelist << "id" << "location" << "name" << "icon" << "termsofuse" << "register";

    while (!reader.atEnd() && !reader.hasError()) {
        reader.readNext();
        if (reader.isStartElement() && reader.name() == "provider") {
            QJsonObject provider;
            provider["_providers_file"] = url.url();
            providers.append(provider);
            continue;
        }
        QString elementName = reader.name().toString();
        if (!providers.isEmpty() && whitelist.contains(elementName)) {
            int i(providers.size() - 1);
            QJsonObject provider = providers[i].toObject();
            provider[elementName] = reader.readElementText();
            providers[i] = provider;
        }
    }

    return providers;
}

} // namespace qtlibs
