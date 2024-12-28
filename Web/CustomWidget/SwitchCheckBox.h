#ifndef SWITCHCHECKBOX_H
#define SWITCHCHECKBOX_H

#include "CheckBox.h"

namespace Widget {

class SwitchCheckBox : public Widget::CheckBox
{
public:
    SwitchCheckBox( const std::string &labelName = "" );
};

} // namespace Widget

#endif // SWITCHCHECKBOX_H
