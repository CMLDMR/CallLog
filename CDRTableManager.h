#ifndef CDRTABLEMANAGER_H
#define CDRTABLEMANAGER_H

#include "CDRTableItem.h"
#include "MongoCore/listitem.h"

class CDRTableManager : public MongoCore::ListItem<CDRTableItem>
{
public:
    CDRTableManager( MongoCore::DB *db );

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const std::vector<CDRTableItem> &mlist) override;
};

#endif // CDRTABLEMANAGER_H
