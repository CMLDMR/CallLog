#include "MainApplication.h"

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WDateEdit.h>

#include "SystemItem.h"

#include "CDRTableManagerContainer.h"
#include "Web/Bootstrap/Bootstrap5ThemeKeys.h"
#include "Web/LoginPanel.h"

using namespace Wt;

MainApplication::MainApplication(const Wt::WEnvironment &env)
    :Wt::WApplication( env )
{

    p_wtTheme = std::make_shared<Wt::WBootstrap5Theme>();
    Wt::WApplication::instance()->setTheme(p_wtTheme);

    ///////////////////////////////////////////////// DB connection
    try {
        m_mongoClient = new mongocxx::client(mongocxx::uri( SystemItem::instance()->mongoUrl() ) );
    } catch ( mongocxx::exception &e) {
        return;
    }

    m_database = m_mongoClient->database( "CallerLog" );
    m_db = new MongoCore::DB( &m_database );
    /////////////////////////////////////////////// End DB connection


    root()->setContentAlignment( AlignmentFlag::Center );
    m_fullPage = root()->addNew<Widget::ContainerWidget>();
    m_fullPage->setMaximumSize( 1280 , WLength::Auto );


    this->loginScreen();

    return;

    auto titleContainer = m_fullPage->header()->addNew<WContainerWidget>();
    titleContainer->addStyleClass( Bootstrap::Grid::full( 12 ) );
    titleContainer->setContentAlignment( AlignmentFlag::Center );
    titleContainer->addNew<WText>( "<h4>Caller Log</h4>" , TextFormat::XHTML );
    titleContainer->addStyleClass( Bootstrap::Utilities::Background::bg_info );


    auto controllerContainer = m_fullPage->header()->addNew<WContainerWidget>();
    controllerContainer->addStyleClass( Bootstrap::Grid::full( 12 ) );

    auto dateSelectContainer = controllerContainer->addNew<WContainerWidget>();
    dateSelectContainer->addStyleClass( Bootstrap::Grid::full( 6 ) );

    auto dateTime = dateSelectContainer->addNew<WDateEdit>();
    dateTime->addStyleClass( Bootstrap::Grid::full( 12 ) );



    auto stateSelectContainer = controllerContainer->addNew<WContainerWidget>();
    stateSelectContainer->addStyleClass( Bootstrap::Grid::full( 6 ) );

    auto cdrManagerContainer = m_fullPage->content()->addNew<CDRTableManagerContainer>( m_db );
    cdrManagerContainer->addStyleClass( Bootstrap::Grid::full( 12 ) );
}

void MainApplication::loginScreen()
{
    m_fullPage->content()->clear();
    m_fullPage->header()->clear();
    m_fullPage->footer()->clear();

    m_fullPage->content() -> addNew<LoginPanel>( m_db )->addStyleClass( Bootstrap::Grid::full( 12 ) );
}




