#include "CDRTableManager.h"

CDRTableManager::CDRTableManager(MongoCore::DB *db)
    :MongoCore::ListItem<CDRTableItem>( db )
{

}


void CDRTableManager::errorOccured(const std::string &errorText)
{
}

void CDRTableManager::onList(const std::vector<CDRTableItem> &mlist)
{

}
