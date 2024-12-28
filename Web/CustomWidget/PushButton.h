#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <Wt/WPushButton.h>

namespace Widget {

class PushButton : public Wt::WPushButton
{
public:
    PushButton( const std::string &title );

};

} // namespace Widget

#endif // PUSHBUTTON_H
