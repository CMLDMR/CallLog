#include "PushButton.h"

#include "Web/CSSGenerator.h"

namespace Widget {

PushButton::PushButton(const std::string &title)
    :Wt::WPushButton( title )
{
    auto selector = CSSGen::createCSS( "btn" , { { "--bs-btn-border-radius","0px !important" } } );
    addStyleClass( selector );
}

} // namespace Widget
