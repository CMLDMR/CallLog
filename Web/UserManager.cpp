#include "UserManager.h"

UserManager::UserManager(MongoCore::DB *db)
    :MongoCore::ListItem<UserItem>( db )
{

}


void UserManager::errorOccured(const std::string &errorText)
{

}

void UserManager::onList(const std::vector<UserItem> &mlist)
{

}
