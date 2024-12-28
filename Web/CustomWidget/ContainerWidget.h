#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include <Wt/WContainerWidget.h>
#include <QObject>

namespace Widget {

class PushButton;
class ListControllerContainer;

class ContainerWidget : public Wt::WContainerWidget
{
public:
    ContainerWidget();

    Wt::WContainerWidget *header() const;

    Wt::WContainerWidget *content() const;
    Wt::WContainerWidget *footer() const;

    ListControllerContainer* controller();


    static Wt::WPushButton* askConfirmationDialog( const std::string &question );
    static std::pair<Widget::PushButton*,Wt::WDialog*> createDialog( const std::string &title , const std::string &btn1Name = QObject::tr("OK").toStdString(), const std::string &btn2Name = QObject::tr("Cancel").toStdString());
    static Wt::WDialog* createInfoDialog( const std::string &title , const std::string &btn1Name = QObject::tr("OK").toStdString() );
    static std::pair<Widget::PushButton*,Wt::WDialog*> createInfoDialogBtn( const std::string &title , const std::string &btn1Name = QObject::tr("OK").toStdString() );

    static void removeDialog( Wt::WDialog* dialog );


private:
    ListControllerContainer* m_controller { nullptr };

    Wt::WContainerWidget* m_header  {nullptr};
    Wt::WContainerWidget* m_content {nullptr};
    Wt::WContainerWidget* m_footer  {nullptr};
};




class ListControllerContainer : public Wt::WContainerWidget
{
public:
    ListControllerContainer();



    Wt::WText *pageInfoText() const;

    Wt::Signal<Wt::NoClass> &backClicked();

    Wt::Signal<Wt::NoClass> &nextClicked();

private:

    Wt::WText* m_pageInfoText { nullptr };

    Wt::Signal<Wt::NoClass> m_backClicked;
    Wt::Signal<Wt::NoClass> m_nextClicked;


    friend class ContainerWidget;
};
}


#endif // CONTAINERWIDGET_H
