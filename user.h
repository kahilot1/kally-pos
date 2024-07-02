#ifndef USER_H
#define USER_H

#include <QString>
class user
{
public:
    enum AuthenticationLevel{
        clerk, financer, ceo
    };
    user(const AuthenticationLevel& userAuthLevel, const int& userID, const QString& username);
    user();

    QString getUsername() const;
    void setUsername(const QString& username);

    AuthenticationLevel getAuLevel() const;
    void setAuLevel(const AuthenticationLevel& auLevel);

    int getUserID() const;
    void setUserID(const int& userID);

private:
    QString m_username;
    int m_userID;
    AuthenticationLevel m_userAuthLevel;

};

#endif // USER_H
