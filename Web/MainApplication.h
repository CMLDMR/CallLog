#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>

class MainApplication : public Wt::WApplication
{
public:
    MainApplication( const Wt::WEnvironment &env );
};

#endif // MAINAPPLICATION_H
