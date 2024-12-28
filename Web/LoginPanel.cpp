#include "LoginPanel.h"

#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WLineEdit.h>
#include "User.h"

#include "Bootstrap/Bootstrap5ThemeKeys.h"

using namespace Wt;

LoginPanel::LoginPanel( MongoCore::DB * db )
{


    m_userManager = std::make_unique<UserManager>( db );


    setContentAlignment( AlignmentFlag::Center );

    auto contentContainer = addNew<WContainerWidget>();

    contentContainer->addStyleClass( Bootstrap::Grid::container_fluid );

    contentContainer->setHeight( 768 );
    contentContainer->setMaximumSize( 640 , WLength::Auto );

    auto vLayout = contentContainer->setLayout( std::make_unique<WVBoxLayout>());

    vLayout->addStretch( 1 );

    auto titleContainer = vLayout->addWidget( std::make_unique<WText>("Giriş Ekranı") , 0 , AlignmentFlag::Justify );
    titleContainer->setAttributeValue( Style::style , Style::background::color::color( Style::color::Grey::LightSlateGray ) + Style::color::color( Style::color::White::AliceBlue ) );
    titleContainer->setInline( false );
    titleContainer->setPadding( 5 , AllSides );


    auto container = vLayout->addWidget( std::make_unique<WContainerWidget>() , 0 , AlignmentFlag::Justify );

    auto rContainer = container->addNew<WContainerWidget>();
    rContainer->addStyleClass( Bootstrap::Grid::row );

    auto userNameContainer = rContainer->addNew<WContainerWidget>();
    userNameContainer->addStyleClass( Bootstrap::Grid::full( 6 ) );
    userNameContainer->setContentAlignment( AlignmentFlag::Right );
    auto userNameText = userNameContainer->addNew<WText> ( "Kullanıcı Adı" );
    userNameText->setTextAlignment( AlignmentFlag::Right );

    userNameContainer->setMargin( 5 , Side::Bottom );


    auto userNameLineEditContainer = rContainer->addNew<WContainerWidget>();
    userNameLineEditContainer->addStyleClass( Bootstrap::Grid::full( 6 ) );
    auto userNameLineEdit = userNameLineEditContainer->addNew<WLineEdit> (  );
    userNameLineEditContainer->setMargin( 5 , Side::Bottom );


    auto passwordContainer = rContainer->addNew<WContainerWidget>();
    passwordContainer->addStyleClass( Bootstrap::Grid::full( 6 ) );
    passwordContainer->setContentAlignment( AlignmentFlag::Right );
    auto passwordText = passwordContainer->addNew<WText> ( "Şifre" );
    passwordText->setTextAlignment( AlignmentFlag::Right );
    passwordContainer->setMargin( 5 , Side::Bottom );



    auto passwordLineEditContainer = rContainer->addNew<WContainerWidget>();
    passwordLineEditContainer->addStyleClass( Bootstrap::Grid::full( 6 ) );
    auto passwordLineEdit = passwordLineEditContainer->addNew<WLineEdit> (  );
    passwordLineEdit->setEchoMode( EchoMode::Password );
    passwordLineEditContainer->setMargin( 5 , Side::Bottom );


    auto blankContainer = rContainer->addNew<WContainerWidget>();
    blankContainer->addStyleClass( Bootstrap::Grid::full( 6 ) );



    auto loginBtnContainer = rContainer->addNew<WContainerWidget>();
    loginBtnContainer->addStyleClass( Bootstrap::Grid::full( 6 ) );
    auto loginBtn = loginBtnContainer->addNew<WPushButton> ( "Giriş" );
    loginBtn->addStyleClass( Bootstrap::Components::Buttons::Outline::Primary + Bootstrap::Components::Buttons::Size::Small );


    loginBtn->clicked().connect( [ = , this ](){

        UserItem filter;
        filter.setUserName( userNameLineEdit->text().toUTF8() );
        filter.setPassword( passwordLineEdit->text().toUTF8() );

        auto userItem = m_userManager->FindOneItem( filter );

        if( userItem.view().empty() ) {

        }
        else{
            m_successLogin.emit(NoClass());
        }
    });




    vLayout->addStretch( 1 );
}

Wt::Signal<NoClass> &LoginPanel::successLogin()
{
    return m_successLogin;
}
