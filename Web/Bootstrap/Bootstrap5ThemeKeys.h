#ifndef BOOTSTRAP5THEMAKEYS_H
#define BOOTSTRAP5THEMAKEYS_H

#include <string>
#include "inlinestyle.h"
#include "NavTabs.h"


//https://getbootstrap.com/docs/5.0/layout/grid/

namespace Bootstrap{

namespace Grid {

inline const std::string container{"container "};
inline const std::string container_fluid{"container-fluid "};

inline const std::string row{"row "};
inline const std::string col{"col "};

const std::string xs( const int index );
const std::string sm( const int index );
const std::string md( const int index );
const std::string lg( const int index );
const std::string xl( const int index );
const std::string xxl( const int index );
const std::string full( const int index );

}

namespace Form_Controls {

namespace Sizing {
inline const std::string form_control_lg{"form-control-lg "};
inline const std::string form_control_sm{"form-control-sm "};
}

}




namespace Components {

inline const std::string badge {"badge "};


namespace Carousel {
inline const std::string carousel{"carousel "};
inline const std::string slide{"slide "};
inline const std::string carousel_indicators{"carousel-indicators "};
inline const std::string carousel_inner{"carousel-inner"};

}

namespace Buttons{

inline const std::string group{"btn-group "};

namespace Normal{
inline const std::string Primary{"btn-primary "};
inline const std::string Secondary{"btn-secondary "};
inline const std::string Success{"btn-success "};
inline const std::string Danger{"btn-danger "};
inline const std::string Warning{"btn-warning "};
inline const std::string Info{"btn-info "};
inline const std::string Light{"btn-light "};
inline const std::string Dark{"btn-dark "};
inline const std::string Link{"btn-link "};
}

namespace Outline{
inline const std::string Primary{"btn-outline-primary "};
inline const std::string Secondary{"btn-outline-secondary "};
inline const std::string Success{"btn-outline-success "};
inline const std::string Danger{"btn-outline-danger "};
inline const std::string Warning{"btn-outline-warning "};
inline const std::string Info{"btn-outline-info "};
inline const std::string Light{"btn-outline-light "};
inline const std::string Dark{"btn-outline-dark "};
inline const std::string Link{"btn-outline-link "};
}

namespace Size{
inline const std::string Large{"btn-lg "};
inline const std::string Small{"btn-sm "};
}

}
}


namespace Utilities {

namespace Display{
inline const std::string hide_all{"d-none "};
inline const std::string hide_xs{"d-none d-sm-block "};
inline const std::string hide_sm{"d-sm-none d-md-block "};
inline const std::string hide_md{"d-md-none d-lg-block "};
inline const std::string hide_lg{"d-lg-none d-xl-block"};
inline const std::string hide_xl{"d-xl-none d-xxl-block "};
inline const std::string hide_xxl{"d-xxl-none "};

inline const std::string visible_all{"d-block "};
inline const std::string visible_xs{"d-block d-sm-none "};
inline const std::string visible_sm{"d-none d-sm-block d-md-none "};
inline const std::string visible_md{"d-none d-md-block d-lg-none "};
inline const std::string visible_lg{"d-none d-lg-block d-xl-none "};
inline const std::string visible_xl{"d-none d-xl-block d-xxl-none "};
inline const std::string visible_xxl{"d-none d-xxl-block "};
}

namespace Flex {
//https://getbootstrap.com/docs/5.0/utilities/flex/
namespace Enable {
inline std::string d_flex("d-flex ");
inline std::string d_inline_flex("d-inline-flex ");
inline std::string d_sm_flex("d-sm-flex ");
inline std::string d_sm_inline_flex("d-sm-inline-flex ");
inline std::string d_md_flex("d-md-flex ");
inline std::string d_md_inline_flex("d-md-inline-flex ");
inline std::string d_lg_flex("d-lg-flex ");
inline std::string d_lg_inline_flex("d-lg-inline-flex ");
inline std::string d_xl_flex("d-xl-flex ");
inline std::string d_xl_inline_flex("d-xl-inline-flex ");
inline std::string d_xxl_flex("d-xxl-flex ");
inline std::string d_xxl_inline_flex("d-xxl-inline-flex ");
}

namespace Directions {
inline std::string flex_row("flex-row ");
inline std::string flex_row_reverse("flex-row-reverse ");
inline std::string flex_column("flex-column ");
inline std::string flex_column_reverse("flex-column-reverse ");
inline std::string flex_sm_row("flex-sm-row ");
inline std::string flex_sm_row_reverse("flex-sm-row-reverse ");
inline std::string flex_sm_column("flex-sm-column ");
inline std::string flex_sm_column_reverse("flex-sm-column-reverse ");
inline std::string flex_md_row("flex-md-row ");
inline std::string flex_md_row_reverse("flex-md-row-reverse ");
inline std::string flex_md_column("flex-md-column ");
inline std::string flex_md_column_reverse("flex-md-column-reverse ");
inline std::string flex_lg_row("flex-lg-row ");
inline std::string flex_lg_row_reverse("flex-lg-row-reverse ");
inline std::string flex_lg_column("flex-lg-column ");
inline std::string flex_lg_column_reverse("flex-lg-column-reverse ");
inline std::string flex_xl_row("flex-xl-row ");
inline std::string flex_xl_row_reverse("flex-xl-row-reverse ");
inline std::string flex_xl_column("flex-xl-column ");
inline std::string flex_xl_column_reverse("flex-xl-column-reverse ");
inline std::string flex_xxl_row("flex-xxl-row ");
inline std::string flex_xxl_row_reverse("flex-xxl-row-reverse ");
inline std::string flex_xxl_column("flex-xxl-column ");
inline std::string flex_xxl_column_reverse("flex-xxl-column-reverse ");
}

namespace JutifyContent{
inline const std::string start("justify-content-start ");
inline const std::string end("justify-content-end ");
inline const std::string center("justify-content-center ");
inline const std::string between("justify-content-between ");
inline const std::string around("justify-content-around ");
inline const std::string evenly("justify-content-evenly ");
inline const std::string sm_start("justify-content-sm-start ");
inline const std::string sm_end("justify-content-sm-end ");
inline const std::string sm_center("justify-content-sm-center ");
inline const std::string sm_between("justify-content-sm-between ");
inline const std::string sm_around("justify-content-sm-around ");
inline const std::string sm_evenly("justify-content-sm-evenly ");
inline const std::string md_start("justify-content-md-start ");
inline const std::string md_end("justify-content-md-end ");
inline const std::string md_center("justify-content-md-center ");
inline const std::string md_between("justify-content-md-between ");
inline const std::string md_around("justify-content-md-around ");
inline const std::string md_evenly("justify-content-md-evenly ");
inline const std::string lg_start("justify-content-lg-start ");
inline const std::string lg_end("justify-content-lg-end ");
inline const std::string lg_center("justify-content-lg-center ");
inline const std::string lg_between("justify-content-lg-between ");
inline const std::string lg_around("justify-content-lg-around ");
inline const std::string lg_evenly("justify-content-lg-evenly ");
inline const std::string xl_start("justify-content-xl-start ");
inline const std::string xl_end("justify-content-xl-end ");
inline const std::string xl_center("justify-content-xl-center ");
inline const std::string xl_between("justify-content-xl-between ");
inline const std::string xl_around("justify-content-xl-around ");
inline const std::string xl_evenly("justify-content-xl-evenly ");
inline const std::string xxl_start("justify-content-xxl-start ");
inline const std::string xxl_end("justify-content-xxl-end ");
inline const std::string xxl_center("justify-content-xxl-center ");
inline const std::string xxl_between("justify-content-xxl-between ");
inline const std::string xxl_around("justify-content-xxl-around ");
inline const std::string xxl_evenly("justify-content-xxl-evenly ");
}

namespace AlignItems {
inline const std::string start("align-items-start ");
inline const std::string end("align-items-end ");
inline const std::string center("align-items-center ");
inline const std::string baseline("align-items-baseline ");
inline const std::string stretch("align-items-stretch ");
inline const std::string sm_start("align-items-sm-start ");
inline const std::string sm_end("align-items-sm-end ");
inline const std::string sm_center("align-items-sm-center ");
inline const std::string sm_baseline("align-items-sm-baseline ");
inline const std::string sm_stretch("align-items-sm-stretch ");
inline const std::string md_start("align-items-md-start ");
inline const std::string md_end("align-items-md-end ");
inline const std::string md_center("align-items-md-center ");
inline const std::string md_baseline("align-items-md-baseline ");
inline const std::string md_stretch("align-items-md-stretch ");
inline const std::string lg_start("align-items-lg-start ");
inline const std::string lg_end("align-items-lg-end ");
inline const std::string lg_center("align-items-lg-center ");
inline const std::string lg_baseline("align-items-lg-baseline ");
inline const std::string lg_stretch("align-items-lg-stretch ");
inline const std::string xl_start("align-items-xl-start ");
inline const std::string xl_end("align-items-xl-end ");
inline const std::string xl_center("align-items-xl-center ");
inline const std::string xl_baseline("align-items-xl-baseline ");
inline const std::string xl_stretch("align-items-xl-stretch ");
inline const std::string xxl_start("align-items-xxl-start ");
inline const std::string xxl_end("align-items-xxl-end ");
inline const std::string xxl_center("align-items-xxl-center ");
inline const std::string xxl_baseline("align-items-xxl-baseline ");
inline const std::string xxl_stretch("align-items-xxl-stretch ");
}

namespace AlignSelf {
inline const std::string start("align-self-start ");
inline const std::string end("align-self-end ");
inline const std::string center("align-self-center ");
inline const std::string baseline("align-self-baseline ");
inline const std::string stretch("align-self-stretch ");
inline const std::string sm_start("align-self-sm-start ");
inline const std::string sm_end("align-self-sm-end ");
inline const std::string sm_center("align-self-sm-center ");
inline const std::string sm_baseline("align-self-sm-baseline ");
inline const std::string sm_stretch("align-self-sm-stretch ");
inline const std::string md_start("align-self-md-start ");
inline const std::string md_end("align-self-md-end ");
inline const std::string md_center("align-self-md-center ");
inline const std::string md_baseline("align-self-md-baseline ");
inline const std::string md_stretch("align-self-md-stretch ");
inline const std::string lg_start("align-self-lg-start ");
inline const std::string lg_end("align-self-lg-end ");
inline const std::string lg_center("align-self-lg-center ");
inline const std::string lg_baseline("align-self-lg-baseline ");
inline const std::string lg_stretch("align-self-lg-stretch ");
inline const std::string xl_start("align-self-xl-start ");
inline const std::string xl_end("align-self-xl-end ");
inline const std::string xl_center("align-self-xl-center ");
inline const std::string xl_baseline("align-self-xl-baseline ");
inline const std::string xl_stretch("align-self-xl-stretch ");
inline const std::string xxl_start("align-self-xxl-start ");
inline const std::string xxl_end("align-self-xxl-end ");
inline const std::string xxl_center("align-self-xxl-center ");
inline const std::string xxl_baseline("align-self-xxl-baseline ");
inline const std::string xxl_stretch("align-self-xxl-stretch ");
}

namespace Fill {
inline const std::string flex_fill("flex-fill ");
inline const std::string flex_sm_fill("flex-sm-fill ");
inline const std::string flex_md_fill("flex-md-fill ");
inline const std::string flex_lg_fill("flex-lg-fill ");
inline const std::string flex_xl_fill("flex-xl-fill ");
inline const std::string flex_xxl_fill("flex-xxl-fill ");
}

namespace GrowShrink {
inline const std::string flex_grow_shrink_0("flex-{grow|shrink}-0 ");
inline const std::string flex_grow_shrink_1("flex-{grow|shrink}-1 ");
inline const std::string flex_sm_grow_shrink_0("flex-sm-{grow|shrink}-0 ");
inline const std::string flex_sm_grow_shrink_1("flex-sm-{grow|shrink}-1 ");
inline const std::string flex_md_grow_shrink_0("flex-md-{grow|shrink}-0 ");
inline const std::string flex_md_grow_shrink_1("flex-md-{grow|shrink}-1 ");
inline const std::string flex_lg_grow_shrink_0("flex-lg-{grow|shrink}-0 ");
inline const std::string flex_lg_grow_shrink_1("flex-lg-{grow|shrink}-1 ");
inline const std::string flex_xl_grow_shrink_0("flex-xl-{grow|shrink}-0 ");
inline const std::string flex_xl_grow_shrink_1("flex-xl-{grow|shrink}-1 ");
inline const std::string flex_xxl_grow_shrink_0("flex-xxl-{grow|shrink}-0 ");
inline const std::string flex_xxl_grow_shrink_1("flex-xxl-{grow|shrink}-1 ");
}

namespace Wrap {
inline const std::string flex_nowrap("flex-nowrap ");
inline const std::string flex_wrap("flex-wrap ");
inline const std::string flex_wrap_reverse("flex-wrap-reverse ");
inline const std::string flex_sm_nowrap("flex-sm-nowrap ");
inline const std::string flex_sm_wrap("flex-sm-wrap ");
inline const std::string flex_sm_wrap_reverse("flex-sm-wrap-reverse ");
inline const std::string flex_md_nowrap("flex-md-nowrap ");
inline const std::string flex_md_wrap("flex-md-wrap ");
inline const std::string flex_md_wrap_reverse("flex-md-wrap-reverse ");
inline const std::string flex_lg_nowrap("flex-lg-nowrap ");
inline const std::string flex_lg_wrap("flex-lg-wrap ");
inline const std::string flex_lg_wrap_reverse("flex-lg-wrap-reverse ");
inline const std::string flex_xl_nowrap("flex-xl-nowrap ");
inline const std::string flex_xl_wrap("flex-xl-wrap ");
inline const std::string flex_xl_wrap_reverse("flex-xl-wrap-reverse ");
inline const std::string flex_xxl_nowrap("flex-xxl-nowrap ");
inline const std::string flex_xxl_wrap("flex-xxl-wrap ");
inline const std::string flex_xxl_wrap_reverse("flex-xxl-wrap-reverse ");
}

namespace Order {
inline const std::string order_first("order-first ");
inline const std::string order_last("order-last ");
inline const std::string order_sm_first("order-sm-first ");
inline const std::string order_sm_last("order-sm-last ");
inline const std::string order_md_first("order-md-first ");
inline const std::string order_md_last("order-md-last ");
inline const std::string order_lg_first("order-lg-first ");
inline const std::string order_lg_last("order-lg-last ");
inline const std::string order_xl_first("order-xl-first ");
inline const std::string order_xl_last("order-xl-last ");
inline const std::string order_xxl_first("order-xxl-first ");
inline const std::string order_xxl_last("order-xxl-last ");
}

namespace AlignContent{
inline const std::string start("align-content-start ");
inline const std::string end("align-content-end ");
inline const std::string center("align-content-center ");
inline const std::string around("align-content-around ");
inline const std::string stretch("align-content-stretch ");
inline const std::string sm_start("align-content-sm-start ");
inline const std::string sm_end("align-content-sm-end ");
inline const std::string sm_center("align-content-sm-center ");
inline const std::string sm_around("align-content-sm-around ");
inline const std::string sm_stretch("align-content-sm-stretch ");
inline const std::string md_start("align-content-md-start ");
inline const std::string md_end("align-content-md-end ");
inline const std::string md_center("align-content-md-center ");
inline const std::string md_around("align-content-md-around ");
inline const std::string md_stretch("align-content-md-stretch ");
inline const std::string lg_start("align-content-lg-start ");
inline const std::string lg_end("align-content-lg-end ");
inline const std::string lg_center("align-content-lg-center ");
inline const std::string lg_around("align-content-lg-around ");
inline const std::string lg_stretch("align-content-lg-stretch ");
inline const std::string xl_start("align-content-xl-start ");
inline const std::string xl_end("align-content-xl-end ");
inline const std::string xl_center("align-content-xl-center ");
inline const std::string xl_around("align-content-xl-around ");
inline const std::string xl_stretch("align-content-xl-stretch ");
inline const std::string xxl_start("align-content-xxl-start ");
inline const std::string xxl_end("align-content-xxl-end ");
inline const std::string xxl_center("align-content-xxl-center ");
inline const std::string xxl_around("align-content-xxl-around ");
inline const std::string xxl_stretch("align-content-xxl-stretch ");
}

}

namespace Border {
namespace Additive{
inline const std::string border{"border "};
inline const std::string border_top{"border-top "};
inline const std::string border_end{"border-end "};
inline const std::string border_bottom{"border-bottom "};
inline const std::string border_start{"border-start "};
}

namespace Subtractive {
inline const std::string border_0("border-0");
inline const std::string border_top_0("border-top-0");
inline const std::string border_end_0("border-end-0");
inline const std::string border_bottom_0("border-bottom-0");
inline const std::string border_start_0("border-start-0");
}

namespace Color {
inline const std::string border_primary("border-primary ");
inline const std::string border_secondary("border-secondary ");
inline const std::string border_success("border-success ");
inline const std::string border_danger("border-danger ");
inline const std::string border_warning("border-warning ");
inline const std::string border_info("border-info ");
inline const std::string border_light("border-light ");
inline const std::string border_dark("border-dark ");
inline const std::string border_white("border-white ");
}

namespace Width {
inline const std::string border_1{"border-1 "};
inline const std::string border_2{"border-2 "};
inline const std::string border_3{"border-3 "};
inline const std::string border_4{"border-4 "};
inline const std::string border_5{"border-5 "};
}

namespace Radius {
inline const std::string rounded{"rounded "};
inline const std::string rounded_top{"rounded-top "};
inline const std::string rounded_end{"rounded-end "};
inline const std::string rounded_bottom{"rounded-bottom "};
inline const std::string rounded_start{"rounded-start "};
inline const std::string rounded_circle{"rounded_circle "};
inline const std::string rounded_pill{"rounded_pill "};
}

namespace Size {
inline const std::string rounded_0{"rounded-0 "};
inline const std::string rounded_1{"rounded-1 "};
inline const std::string rounded_2{"rounded-2 "};
inline const std::string rounded_3{"rounded-3 "};
}

}

namespace Background {

inline const std::string gradient{"bg-gradient "};
inline const std::string bg_primary{"bg-primary "};
inline const std::string bg_secondary{"bg-secondary "};
inline const std::string bg_success{"bg-success "};
inline const std::string bg_danger{"bg-danger "};
inline const std::string bg_warning{"bg-warning "};
inline const std::string bg_info{"bg-info "};
inline const std::string bg_light{"bg-light "};
inline const std::string bg_dark{"bg-dark "};


}

namespace Shadow {
inline const std::string shadow_sm{"shadow-sm "};
inline const std::string shadow{"shadow "};
inline const std::string shadow_lg{"shadow-lg "};
}

namespace Text {
inline const std::string text_start{"text-start "};
inline const std::string text_center{"text-center "};
inline const std::string text_end{"text-end "};
inline const std::string text_sm_start{"text-sm-start "};
inline const std::string text_md_start{"text-md-start "};
inline const std::string text_lg_start{"text-lg-start "};
inline const std::string text_xl_start{"text-xl-start "};
inline const std::string text_wrap{"text-wrap "};
inline const std::string text_break{"text-break "};
inline const std::string text_lowercase{"text-lowercase "};
inline const std::string text_uppercase{"text-uppercase "};
inline const std::string text_capitalize{"text-capitalize "};

inline const std::string fw_bold{"fw-bold "};
inline const std::string fw_bolder{"fw-bolder "};
inline const std::string fw_normal{"fw-normal "};
inline const std::string fw_light{"fw-light "};
inline const std::string fw_lighter{"fw-lighter "};
inline const std::string fst_italic{"fst-italic "};
inline const std::string fst_normal{"fst-normal "};

namespace Size{
inline const std::string fs_1{"fs-1 "};
inline const std::string fs_2{"fs-2 "};
inline const std::string fs_3{"fs-3 "};
inline const std::string fs_4{"fs-4 "};
inline const std::string fs_5{"fs-5 "};
inline const std::string fs_6{"fs-6 "};
}

}


}

}



#endif // BOOTSTRAP5THEMAKEYS_H
