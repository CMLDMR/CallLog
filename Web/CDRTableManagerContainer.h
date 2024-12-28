#ifndef CDRTABLEMANAGERCONTAINER_H
#define CDRTABLEMANAGERCONTAINER_H

#include <Wt/WContainerWidget.h>
#include "CDRTableManager.h"

class CDRTableManagerContainer : public Wt::WContainerWidget, CDRTableManager
{
public:
    CDRTableManagerContainer( MongoCore::DB * db );

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // CDRTableManager interface
public:
    virtual void onList(const std::vector<CDRTableItem> &mlist) override;
};

#endif // CDRTABLEMANAGERCONTAINER_H
