#include "CDRTableManager.h"

CDRTableManager::CDRTableManager(MongoCore::DB *db)
    :MongoCore::ListItem<CDRTableItem>( db )
{

}
