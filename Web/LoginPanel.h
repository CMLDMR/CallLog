#ifndef LOGINPANEL_H
#define LOGINPANEL_H

#include <Wt/WContainerWidget.h>

#include "UserManager.h"

class LoginPanel : public Wt::WContainerWidget
{
public:
    LoginPanel( MongoCore::DB * db );



    Wt::Signal<Wt::NoClass> &successLogin();

private:
    std::unique_ptr<UserManager> m_userManager;

    Wt::Signal<Wt::NoClass> m_successLogin;
};

#endif // LOGINPANEL_H
