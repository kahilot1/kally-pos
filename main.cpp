#include "loginmenu.h"
#include "usermanager.h"

#include <QApplication>

void onCurrentUserChanged(const user &use){
    qDebug() << "FROM SIGNAL: current user is now " << use.getAuLevel();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    usermanager& manager = usermanager::instance();
    QObject::connect(&manager, &usermanager::currentUserChanged, &onCurrentUserChanged);
    loginMenu w;
    w.show();
    return a.exec();
}
