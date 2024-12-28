#include "CheckBox.h"

using namespace Wt;

namespace Widget {

CheckBox::CheckBox(const std::string &labelName)
    :Wt::WCheckBox( labelName )
{
    setMargin( Wt::WLength::Auto , Side::Bottom | Side::Top );
}

} // namespace Widget
