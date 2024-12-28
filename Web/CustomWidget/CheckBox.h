#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <Wt/WCheckBox.h>

namespace Widget {

class CheckBox : public Wt::WCheckBox
{
public:
    CheckBox( const std::string &labelName = "" );
};

} // namespace Widget

#endif // CHECKBOX_H
