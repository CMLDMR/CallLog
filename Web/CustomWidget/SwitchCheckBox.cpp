#include "SwitchCheckBox.h"
#include "DauCore/DauCoreItem/Logger.h"

#include <Wt/WLabel.h>

using namespace Wt;

namespace Widget {

SwitchCheckBox::SwitchCheckBox(const std::string &labelName)
    :Widget::CheckBox( labelName )
{
    addStyleClass( "form-switch" );

}

} // namespace Widget

