#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>
#include "user.h"

class usermanager : public QObject
{
    Q_OBJECT

public:
    static usermanager& instance();

    user getCurrentUser() const;
    void setCurrentUser(const user& user);


signals:
    void currentUserChanged(const user& user);

private:
    usermanager() {}
    usermanager(const usermanager&) = delete;
    usermanager& operator=(const usermanager&) = delete;

    user m_currentUser;
};

#endif // USERMANAGER_H
