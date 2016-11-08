#include <QDebug>
#include <QCoreApplication>

#include "../libs/utils/file.h"
#include "../libs/utils/dir.h"
#include "../libs/utils/json.h"
#include "../libs/utils/config.h"
#include "../libs/utils/network.h"

#if defined(Q_OS_UNIX) && !defined(Q_OS_IOS) && !defined(Q_OS_ANDROID)
#include "../libs/utils/package.h"
#endif

#if defined(Q_OS_ANDROID)
#include "../libs/utils/android.h"
#endif

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // testing ////////////////////////////////////////////

    qDebug() << "testing";

    // testing ////////////////////////////////////////////

    app.exit();
}
