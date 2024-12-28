#include "ContainerWidget.h"

#include "Web/Bootstrap/Bootstrap5ThemeKeys.h"
#include "Web/CSSGenerator.h"

#include <Wt/WApplication.h>
#include <Wt/WDialog.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include "Web/CustomWidget/PushButton.h"


#include <QObject>

using namespace Wt;

namespace Widget {

ContainerWidget::ContainerWidget()
{

    addStyleClass( Bootstrap::Grid::container_fluid );
    setContentAlignment( AlignmentFlag::Center );
    m_header = addNew<WContainerWidget>();
    m_header->addStyleClass( Bootstrap::Grid::row );

    m_content = addNew<WContainerWidget>();
    m_content->addStyleClass( Bootstrap::Grid::row );

    m_footer = addNew<WContainerWidget>();
    m_footer->addStyleClass( Bootstrap::Grid::row );
}

Wt::WContainerWidget *ContainerWidget::header() const
{
    return m_header;
}

Wt::WContainerWidget *ContainerWidget::content() const
{
    return m_content;
}

Wt::WContainerWidget *ContainerWidget::footer() const
{
    return m_footer;
}

ListControllerContainer *ContainerWidget::controller()
{

    if( ! m_controller ) {
        m_controller = m_footer->addNew<ListControllerContainer>();
    }
    return m_controller;
}

WPushButton *ContainerWidget::askConfirmationDialog( const std::string &question )
{

    auto mDialog = wApp->instance()->root()->addChild (std::make_unique<WDialog>());

    auto selector = CSSGen::createCSS("model", { { "--bs-modal-border-radius" , "0px !important" } ,
                                                { "--bs-modal-header-padding" , "3px 3px !important" }} );

    auto selector1 = CSSGen::createCSS("model-header", { { "border-top-left-radius" , "0px !important" } ,
                                                        { "border-top-right-radius" , "0px !important" }} );

    mDialog->addStyleClass( selector );

    mDialog->titleBar()->addStyleClass( selector1 );

    mDialog->titleBar()->setAttributeValue( Style::style , Style::background::color::color( Style::color::Grey::LightSlateGray ) + Style::color::color( Style::color::White::AliceBlue ) + Style::font::size::s14px );

    mDialog->setWindowTitle( QObject::tr("Warning").toStdString() );


    mDialog->contents ()->addWidget (std::make_unique<WText>( question , TextFormat::XHTML ));
    mDialog->contents ()->addStyleClass (Bootstrap::Utilities::Background::bg_warning );
    mDialog->contents()->setPadding( 10 , AllSides );

    auto yesBtn = mDialog->footer ()->addWidget (std::make_unique<WPushButton>( QObject::tr("Yes").toStdString() ));
    yesBtn->addStyleClass (Bootstrap::Components::Buttons::Normal::Primary);

    auto closeBtn = mDialog->footer ()->addWidget (std::make_unique<WPushButton>( QObject::tr("No").toStdString() ));
    closeBtn->addStyleClass ( Bootstrap::Components::Buttons::Outline::Danger );

    closeBtn->clicked ().connect ([=](){
        wApp->instance()->root()->removeChild(mDialog);
    });

    yesBtn->clicked ().connect ([=](){
        wApp->instance()->root()->removeChild(mDialog);
    });

    mDialog->show ();
    return yesBtn;
}

std::pair<Widget::PushButton *, WDialog *> ContainerWidget::createDialog(const std::string &title , const std::string &btn1Name , const std::string &btn2Name )
{

    auto mDialog = wApp->instance()->root()->addChild (std::make_unique<WDialog>());

    auto selector = CSSGen::createCSS("model", { { "--bs-modal-border-radius" , "0px !important" } ,
                                                { "--bs-modal-header-padding" , "3px 3px !important" }} );

    auto selector1 = CSSGen::createCSS("model-header", { { "border-top-left-radius" , "0px !important" } ,
                                                { "border-top-right-radius" , "0px !important" }} );

    mDialog->addStyleClass( selector );

    mDialog->titleBar()->addStyleClass( selector1 );

    mDialog->titleBar()->setAttributeValue( Style::style , Style::background::color::color( Style::color::Grey::LightSlateGray ) + Style::color::color( Style::color::White::AliceBlue ) + Style::font::size::s14px );

    mDialog->setWindowTitle( title );

    mDialog->contents()->setPadding( 10 , AllSides );

    Widget::PushButton* yesBtn;
    if( btn1Name.size() ) {
        yesBtn = mDialog->footer ()->addWidget (std::make_unique<Widget::PushButton>( btn1Name ));
        yesBtn->addStyleClass (Bootstrap::Components::Buttons::Normal::Primary + Bootstrap::Components::Buttons::Size::Small );
    }


    auto closeBtn = mDialog->footer ()->addWidget (std::make_unique<Widget::PushButton>( btn2Name ));
    closeBtn->addStyleClass ( Bootstrap::Components::Buttons::Outline::Secondary + Bootstrap::Components::Buttons::Size::Small  );

    closeBtn->clicked ().connect ([=](){
        wApp->instance()->root()->removeChild(mDialog);
    });

    // mDialog->setWidth( 450 );

    mDialog->show ();
    if( btn1Name.size() ) {
        return std::make_pair(yesBtn,mDialog);
    }else{
        return std::make_pair(closeBtn,mDialog);
    }
}

WDialog *ContainerWidget::createInfoDialog(const std::string &title, const std::string &btn1Name)
{

    auto mDialog = wApp->instance()->root()->addChild (std::make_unique<WDialog>());

    auto selector = CSSGen::createCSS("model", { { "--bs-modal-border-radius" , "0px !important" } ,
                                                { "--bs-modal-header-padding" , "3px 3px !important" }} );

    auto selector1 = CSSGen::createCSS("model-header", { { "border-top-left-radius" , "0px !important" } ,
                                                        { "border-top-right-radius" , "0px !important" }} );

    mDialog->addStyleClass( selector );

    mDialog->titleBar()->addStyleClass( selector1 );

    mDialog->titleBar()->setAttributeValue( Style::style , Style::background::color::color( Style::color::Grey::LightSlateGray ) + Style::color::color( Style::color::White::AliceBlue ) + Style::font::size::s14px );

    mDialog->setWindowTitle( title );

    mDialog->contents()->setPadding( 10 , AllSides );

    Widget::PushButton* yesBtn;
    if( btn1Name.size() ) {
        yesBtn = mDialog->footer ()->addWidget (std::make_unique<Widget::PushButton>( btn1Name ));
        yesBtn->addStyleClass (Bootstrap::Components::Buttons::Normal::Primary + Bootstrap::Components::Buttons::Size::Small );
    }


    yesBtn->clicked ().connect ([=](){
        wApp->instance()->root()->removeChild(mDialog);
    });

    // mDialog->setWidth( 450 );

    mDialog->show ();

    return mDialog;
}

std::pair<PushButton *, WDialog *> ContainerWidget::createInfoDialogBtn(const std::string &title, const std::string &btn1Name)
{

    auto mDialog = wApp->instance()->root()->addChild (std::make_unique<WDialog>());

    auto selector = CSSGen::createCSS("model", { { "--bs-modal-border-radius" , "0px !important" } ,
                                                { "--bs-modal-header-padding" , "3px 3px !important" }} );

    auto selector1 = CSSGen::createCSS("model-header", { { "border-top-left-radius" , "0px !important" } ,
                                                        { "border-top-right-radius" , "0px !important" }} );

    mDialog->addStyleClass( selector );

    mDialog->titleBar()->addStyleClass( selector1 );

    mDialog->titleBar()->setAttributeValue( Style::style , Style::background::color::color( Style::color::Grey::LightSlateGray ) + Style::color::color( Style::color::White::AliceBlue ) + Style::font::size::s14px );

    mDialog->setWindowTitle( title );

    mDialog->contents()->setPadding( 10 , AllSides );

    Widget::PushButton* yesBtn;
    if( btn1Name.size() ) {
        yesBtn = mDialog->footer ()->addWidget (std::make_unique<Widget::PushButton>( btn1Name ));
        yesBtn->addStyleClass (Bootstrap::Components::Buttons::Normal::Primary + Bootstrap::Components::Buttons::Size::Small );
    }



    // mDialog->setWidth( 450 );

    mDialog->show ();

    return std::make_pair(yesBtn , mDialog );
}

void ContainerWidget::removeDialog(Wt::WDialog *dialog)
{
    wApp->instance()->root()->removeChild( dialog );
}

ListControllerContainer::ListControllerContainer()
{

    auto hLayout = setLayout( std::make_unique<WHBoxLayout>());

    hLayout->addStretch( 1 );

    auto backButton = hLayout->addWidget( std::make_unique<Widget::PushButton>( QObject::tr("Back").toStdString() ) );
    backButton->addStyleClass( Bootstrap::Components::Buttons::Size::Small + Bootstrap::Components::Buttons::Outline::Secondary );
    backButton->clicked().connect([=, this](){
        this->m_backClicked.emit( NoClass() );
    });

    hLayout->addSpacing( 25 );
    m_pageInfoText = hLayout->addWidget( std::make_unique<WText>("1/1"));
    m_pageInfoText->decorationStyle().font().setWeight( FontWeight::Bold );
    hLayout->addSpacing( 25 );

    auto nextButton = hLayout->addWidget( std::make_unique<Widget::PushButton>( QObject::tr("Next").toStdString() ) );
    nextButton->addStyleClass( Bootstrap::Components::Buttons::Size::Small + Bootstrap::Components::Buttons::Outline::Secondary );
    nextButton->clicked().connect([=, this](){
        this->m_nextClicked.emit( NoClass() );
    });

    hLayout->addStretch( 1 );

}

Wt::WText *ListControllerContainer::pageInfoText() const
{
    return m_pageInfoText;
}

Wt::Signal<Wt::NoClass> &ListControllerContainer::backClicked()
{
    return m_backClicked;
}

Wt::Signal<Wt::NoClass> &ListControllerContainer::nextClicked()
{
    return m_nextClicked;
}

}
