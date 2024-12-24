#include "MainApplication.h"

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>


using namespace Wt;

MainApplication::MainApplication(const Wt::WEnvironment &env)
    :Wt::WApplication( env )
{
    root()->addNew<WText>( "ENV" );
}
