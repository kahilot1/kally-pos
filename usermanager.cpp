#include "usermanager.h"

usermanager& usermanager::instance(){
    static usermanager instance;
    return instance;
}

user usermanager::getCurrentUser() const{
    return m_currentUser;
}

void usermanager::setCurrentUser(const user& use){
    if ((m_currentUser.getUsername() == "") || m_currentUser.getUserID() != use.getUserID()){
        m_currentUser = use;
        emit currentUserChanged(m_currentUser);
    }
}


