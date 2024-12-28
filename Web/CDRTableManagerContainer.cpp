#include "CDRTableManagerContainer.h"

CDRTableManagerContainer::CDRTableManagerContainer(MongoCore::DB *db)
    :CDRTableManager( db )
{

}


void CDRTableManagerContainer::errorOccured(const std::string &errorText)
{

}

void CDRTableManagerContainer::onList(const std::vector<CDRTableItem> &mlist)
{

}
