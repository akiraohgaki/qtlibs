/**
 * A library for Qt app
 *
 * LICENSE: The GNU Lesser General Public License, version 3.0
 *
 * @author      Akira Ohgaki <akiraohgaki@gmail.com>
 * @copyright   Akira Ohgaki
 * @license     https://opensource.org/licenses/LGPL-3.0  The GNU Lesser General Public License, version 3.0
 * @link        https://github.com/akiraohgaki/qt-libs
 */

#pragma once

#include <QObject>

namespace utils {

class File : public QObject
{
    Q_OBJECT

public:
    explicit File(const QString &path, QObject *parent = 0);

    QString path() const;
    void setPath(const QString &path);

    bool exists();
    QString readText();
    bool writeText(const QString &data);
    QByteArray readBinary();
    bool writeBinary(const QByteArray &data);
    bool copy(const QString &newPath);
    bool move(const QString &newPath);
    bool remove();

private:
    QString path_;
};

} // namespace utils
