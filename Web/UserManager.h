#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "MongoCore/listitem.h"
#include "User.h"

class UserManager : public MongoCore::ListItem<UserItem>
{
public:
    UserManager( MongoCore::DB * db );

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const std::vector<UserItem> &mlist) override;
};

#endif // USERMANAGER_H
