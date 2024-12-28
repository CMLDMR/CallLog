#include "Panel.h"
#include "Web/CSSGenerator.h"
#include "Web/Bootstrap/Bootstrap5ThemeKeys.h"

namespace Widget {

Panel::Panel()
{
    auto selector = CSSGen::createCSS( "--bs-card-border-radius" , { {"border-radius","0px !important"} });
    addStyleClass( selector );
}

} // namespace Widget
