#include "user.h"

user::user(){}
user::user(const AuthenticationLevel& userAuthLevel, const int& userID, const QString& username)
    : m_username(username), m_userID(userID), m_userAuthLevel(userAuthLevel) {}

QString user::getUsername() const{
    return m_username;
}
void user::setUsername(const QString& username){
    m_username = username;
}

user::AuthenticationLevel user::getAuLevel() const{
    return m_userAuthLevel;
}
void user::setAuLevel(const user::AuthenticationLevel& auLevel){
    m_userAuthLevel = auLevel;
}

int user::getUserID() const{
    return m_userID;
}
void user::setUserID(const int& userID){
    m_userID = userID;
}

