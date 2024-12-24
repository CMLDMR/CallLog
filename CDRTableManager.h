#ifndef CDRTABLEMANAGER_H
#define CDRTABLEMANAGER_H

#include "CDRTableItem.h"
#include "MongoCore/listitem.h"

class CDRTableManager : public MongoCore::ListItem<CDRTableItem>
{
public:
    CDRTableManager();
};

#endif // CDRTABLEMANAGER_H
