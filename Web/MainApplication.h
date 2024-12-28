#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WBootstrap5Theme.h>
#include "MongoCore/db.h"
#include <mongocxx/client.hpp>
#include <mongocxx/database.hpp>

#include "CustomWidget/ContainerWidget.h"

class MainApplication : public Wt::WApplication
{
public:
    MainApplication( const Wt::WEnvironment &env );

    void loginScreen();

private:
    std::shared_ptr<Wt::WBootstrap5Theme> p_wtTheme;

    mongocxx::client* m_mongoClient { nullptr };
    mongocxx::database m_database;;

    MongoCore::DB *m_db;


    Widget::ContainerWidget* m_fullPage;

};

#endif // MAINAPPLICATION_H
