#ifndef INLINESTYLE_H
#define INLINESTYLE_H


#include <iostream>
#include <string>





namespace Style {
inline const std::string style{"style"};
inline const std::string dataoid{"data-oid"};
inline const std::string userdata1{"userData1"};
inline const std::string userdata2{"userData2"};
inline const std::string customData{"customDatas"};
namespace color {
inline const std::string rgb(const int r , const int g , const int b ){ return "color:rgb(" + std::to_string( r ) + "," + std::to_string( g ) + "," + std::to_string( b ) + ");" ; };
inline const std::string rgb(const std::string &rgb){return std::string{"color:rgb("+rgb+");"};};
inline const std::string rgba(const std::string &rgba){return std::string{"color:rgba("+rgba+");"};};
inline const std::string color(const std::string &color){return std::string{"color:"+color+";"};};
namespace Pink {
inline const std::string Pink {"Pink ;"};
inline const std::string LightPink {"LightPink ;"};
inline const std::string HotPink {"HotPink ;"};
inline const std::string DeepPink {"DeepPink ;"};
inline const std::string PaleVioletRed {"PaleVioletRed ;"};
inline const std::string MediumVioletRed {"MediumVioletRed ;"};
}
namespace Purple {
inline const std::string LightSkyBlue {"lightskyblue ;"};
inline const std::string Lavender {"Lavender ;"};
inline const std::string Thistle  {"Thistle ;"};
inline const std::string Plum  {"Plum ;"};
inline const std::string Orchid  {"Orchid ;"};
inline const std::string Violet  {"Violet ;"};
inline const std::string Fuchsia  {"Fuchsia ;"};
inline const std::string Magenta  {"Magenta ;"};
inline const std::string MediumOrchid  {"MediumOrchid ;"};
inline const std::string DarkOrchid  {"DarkOrchid ;"};
inline const std::string DarkViolet  {"DarkViolet ;"};
inline const std::string DodgerBlue  {"DodgerBlue ;"};
inline const std::string BlueViolet  {"BlueViolet ;"};
inline const std::string DarkMagenta   {"DarkMagenta ;"};
inline const std::string Purple   {"Purple ;"};
inline const std::string MediumPurple   {"MediumPurple ;"};
inline const std::string MediumSlateBlue   {"MediumSlateBlue ;"};
inline const std::string SlateBlue   {"SlateBlue ;"};
inline const std::string DarkSlateBlue   {"DarkSlateBlue ;"};
inline const std::string RebeccaPurple   {"RebeccaPurple ;"};
inline const std::string Indigo {"Indigo ;"};
inline const std::string MidnightBlue{"MidnightBlue;"};
inline const std::string RoyalBlue{"RoyalBlue;"};
}
namespace Red {
inline const std::string LightSalmon  {"LightSalmon ;"};
inline const std::string Salmon   {"Salmon ;"};
inline const std::string DarkSalmon   {"DarkSalmon ;"};
inline const std::string LightCoral   {"LightCoral ;"};
inline const std::string IndianRed    {"IndianRed ;"};
inline const std::string Crimson   {"Crimson ;"};
inline const std::string Red   {"Red ;"};
inline const std::string FireBrick   {"FireBrick ;"};
inline const std::string DarkRed   {"DarkRed ;"};
}
namespace Orange {
inline const std::string Orange  {"Orange ;"};
inline const std::string DarkOrange    {"DarkOrange ;"};
inline const std::string Coral    {"Coral ;"};
inline const std::string Tomato    {"Tomato ;"};
inline const std::string OrangeRed     {"OrangeRed ;"};
inline const std::string GoldenRod     {"GoldenRod ;"};
}
namespace Yellow {
inline const std::string Gold{"Gold;"};
inline const std::string Yellow{"Yellow;"};
inline const std::string LightYellow{"LightYellow;"};
inline const std::string LemonChiffon{"LemonChiffon;"};
inline const std::string LightGoldenRodYellow{"LightGoldenRodYellow;"};
inline const std::string PapayaWhip{"PapayaWhip;"};
inline const std::string Moccasin{"Moccasin;"};
inline const std::string PeachPuff{"PeachPuff;"};
inline const std::string PaleGoldenRod{"PaleGoldenRod;"};
inline const std::string Khaki{"Khaki;"};
inline const std::string DarkKhaki{"DarkKhaki;"};
}
namespace Green {
inline const std::string GreenYellow{"GreenYellow;"};
inline const std::string Chartreuse{"Chartreuse;"};
inline const std::string LawnGreen{"LawnGreen;"};
inline const std::string Lime{"Lime;"};
inline const std::string LimeGreen{"LimeGreen;"};
inline const std::string PaleGreen{"PaleGreen;"};
inline const std::string LightGreen{"LightGreen;"};
inline const std::string MediumSpringGreen{"MediumSpringGreen;"};
inline const std::string SpringGreen{"SpringGreen;"};
inline const std::string MediumSeaGreen{"MediumSeaGreen;"};
inline const std::string SeaGreen{"SeaGreen;"};
inline const std::string ForestGreen{"ForestGreen;"};
inline const std::string Green{"Green;"};
inline const std::string DarkGreen{"DarkGreen;"};
inline const std::string YellowGreen{"YellowGreen;"};
inline const std::string OliveDrab{"OliveDrab;"};
inline const std::string DarkOliveGreen{"DarkOliveGreen;"};
inline const std::string MediumAquaMarine{"MediumAquaMarine;"};
inline const std::string DarkSeaGreen{"DarkSeaGreen;"};
inline const std::string LightSeaGreen{"LightSeaGreen;"};
inline const std::string DarkCyan{"DarkCyan;"};
inline const std::string Teal{"Teal;"};
}
namespace White {
inline const std::string White{"White;"};
inline const std::string Snow{"Snow;"};
inline const std::string HoneyDew{"HoneyDew;"};
inline const std::string MintCream {"MintCream;"};
inline const std::string Azure{"Azure;"};
inline const std::string AliceBlue{"AliceBlue;"};
inline const std::string GhostWhite{"GhostWhite;"};
inline const std::string WhiteSmoke{"WhiteSmoke;"};
inline const std::string SeaShell{"SeaShell;"};
inline const std::string OldLace{"OldLace;"};
inline const std::string FloralWhite{"FloralWhite;"};
inline const std::string Ivory{"Ivory;"};
inline const std::string AntiqueWhite{"AntiqueWhite;"};
inline const std::string Linen{"Linen;"};
inline const std::string LavenderBlush{"LavenderBlush;"};
inline const std::string MistyRose{"MistyRose;"};
}
namespace Grey {
inline const std::string Gainsboro{"Gainsboro;"};
inline const std::string LightGray{"LightGray;"};
inline const std::string Silver{"Silver;"};
inline const std::string DarkGray {"DarkGray;"};
inline const std::string DimGray{"DimGray;"};
inline const std::string Gray{"Gray;"};
inline const std::string LightSlateGray{"LightSlateGray;"};
inline const std::string SlateGray{"SlateGray;"};
inline const std::string DarkSlateGray{"DarkSlateGray;"};
inline const std::string Black{"Black;"};
}
}


namespace Affix {
inline const std::string data_spy{"data-spy"};
inline const std::string affix{"affix"};
inline const std::string affix_top{"affix-top"};
inline const std::string affix_bottom{"affix-bottom"};
inline const std::string offsetTop( int offsetTop = 0 ){ return "data-offset-top=\""+std::to_string(offsetTop)+"\"";}
inline const std::string offsetBottom( int offsetBottom = 0 ){ return "data-offset-bottom=\""+std::to_string(offsetBottom)+"\"";}
}


namespace font {
namespace size {
inline const std::string s72px{"font-size:72px;"};
inline const std::string s64px{"font-size:64px;"};
inline const std::string s48px{"font-size:48px;"};
inline const std::string s36px{"font-size:36px;"};
inline const std::string s28px{"font-size:28px;"};
inline const std::string s24px{"font-size:24px;"};
inline const std::string s20px{"font-size:20px;"};
inline const std::string s18px{"font-size:18px;"};
inline const std::string s16px{"font-size:16px;"};
inline const std::string s14px{"font-size:14px;"};
inline const std::string s12px{"font-size:12px;"};
inline const std::string s11px{"font-size:11px;"};
inline const std::string s10px{"font-size:10px;"};
inline const std::string s9px{"font-size:9px;"};
inline const std::string s8px{"font-size:8px;"};
}
namespace family {
inline const std::string tahoma{"font-family:tahoma;"};
inline const std::string dosis{"font-family: 'Dosis', sans-serif;"};
}
namespace weight {
inline const std::string bold{"font-weight:bold;"};
inline const std::string normal{"font-weight:normal;"};
inline const std::string lighter{"font-weight:lighter;"};
}
}

namespace background {
inline std::string url(const std::string& imgPath){return std::string{"background:url("+imgPath+");"};};

namespace color {
inline const std::string rgb(const std::string& rgb){return std::string{"background-color:rgb("+rgb+");"};};
inline const std::string rgb(int r , int g , int b ){return std::string{ "background-color:rgb(" +std::to_string(r)+","+std::to_string(g)+","+std::to_string(b)+");" };};
inline const std::string rgba(int r , int g , int b , double a = 0.5 ){return std::string{ "background-color:rgba(" +std::to_string(r)+","+std::to_string(g)+","+std::to_string(b)+","+std::to_string(a)+");" };};
inline const std::string rgba(const std::string& rgba){return std::string{"background-color:rgba("+rgba+");"};};
inline const std::string color(const std::string& color){return std::string{"background-color:"+color+";"};};
}

namespace size {
inline const std::string contain{"background-size:contain;"};
inline const std::string initial{"background-size:initial;"};
inline const std::string cover{"background-size:cover;"};
inline const std::string auto_{"background-size:auto;"};
inline const std::string length(const std::string &inpixel){return std::string{"background-size:"+inpixel+"px;"};};
inline const std::string length(const std::string &inpixel1,const std::string &inpixel2){return std::string{"background-size:"+inpixel1+"px "+inpixel2+"px;"};};
inline const std::string percentage(const std::string &inper){return std::string{"background-size:"+inper+";"};};
inline const std::string percentage(const std::string &inper1,const std::string &inper2){return std::string{"background-size:"+inper1+" "+inper2+";"};};
}
namespace repeat {
inline const std::string repeat{"background-repeat:repeat;"};
inline const std::string repeat_x{"background-repeat:repeat-x;"};
inline const std::string repeat_y{"background-repeat:repeat-y;"};
inline const std::string repeat_x_y{"background-repeat:repeat-x-y;"};
inline const std::string norepeat{"background-repeat:no-repeat;"};
inline const std::string round{"background-repeat:round;"};
inline const std::string space{"background-repeat:space;"};
}
namespace origin {
inline const std::string padding_box{"background-origin:padding-box;"};
inline const std::string border_box{"background-origin:border-box;"};
inline const std::string content_box{"background-origin:content-box;"};
}
namespace attachment {
inline const std::string scroll{"background-attachment:scroll;"};
inline const std::string fixed{"background-attachment:fixed;"};
inline const std::string local{"background-attachment:local;"};
}
namespace blend_mode {
inline const std::string normal{"background-blend-mode:normal;"};
inline const std::string multiply{"background-blend-mode:multiply;"};
inline const std::string screen{"background-blend-mode:screen;"};
inline const std::string overlay{"background-blend-mode:overlay;"};
inline const std::string darken{"background-blend-mode:darken;"};
inline const std::string lighten{"background-blend-mode:lighten;"};
inline const std::string color_dodge{"background-blend-mode:color-dodge;"};
inline const std::string saturation{"background-blend-mode:saturation;"};
inline const std::string color{"background-blend-mode:color;"};
inline const std::string luminosity{"background-blend-mode:luminosity;"};
}
namespace clip {
inline const std::string border_box{"background-clip:border-box;"};
inline const std::string padding_box{"background-clip:padding-box;"};
inline const std::string content_box{"background-clip:content-box;"};
}
namespace position {
inline const std::string left_top{"background-position:left top;"};
inline const std::string left_center{"background-position:left center;"};
inline const std::string left_bottom{"background-position:left bottom;"};
inline const std::string right_top{"background-position:right top;"};
inline const std::string right_center{"background-position:right center;"};
inline const std::string right_bottom{"background-position:right bottom;"};
inline const std::string center_top{"background-position:center top;"};
inline const std::string center_center{"background-position:center center;"};
inline const std::string center_bottom{"background-position:center bottom;"};
inline const std::string pos(const std::string &xpos , const std::string &ypos){return std::string{"background-position:"+xpos+" "+ypos+";"};};
inline const std::string percentage(const std::string &per1 , const std::string &per2){return std::string{"background-position:"+per1+"% "+per2+"%;"};};
}
}

namespace Border {
inline std::string border(const std::string &borderText){return std::string{"border:"+borderText+";"};};
inline std::string borderRardius(const std::string &radius1, const std::string &radius2 = "0" , const std::string &radius3 = "0" , const std::string &radius4 = "0")
{return std::string{"border-radius:"+radius1+"px "+radius2+"px "+radius3+"px "+radius4+"px;"};};
namespace width {
inline std::string medium{"-width:medium;"};
inline std::string thin{"-width:thin;"};
inline std::string thick{"-width:thick;"};
inline std::string length(const std::string &inpixel){return std::string{"-width:"+inpixel+"px;"};};
}
namespace style {
inline std::string none{"-style:none;"};
inline std::string hidden{"-style:hidden;"};
inline std::string dotted{"-style:dotted;"};
inline std::string dashed{"-style:dashed;"};
inline std::string solid{"-style:solid;"};
inline std::string double_{"-style:double;"};
inline std::string groove{"-style:groove;"};
inline std::string ridge{"-style:ridge;"};
inline std::string inset{"-style:inset;"};
inline std::string outset{"-style:outset;"};
}
namespace bottom {
inline std::string border(std::string borderText){return std::string{"border-bottom:"+borderText+";"};};
inline std::string border_width(std::string Borderwidth){ return "border-bottom:"+Borderwidth+";";};
inline std::string border_style(std::string Borderstyle){ return "border-bottom:"+Borderstyle+";";};
inline std::string border_color(std::string rgb,std::string a = "1"){ return "border-bottom-color:rgb("+rgb+","+a+");";};
}
namespace right {
inline std::string border(std::string borderText){return std::string{"border-right:"+borderText+";"};};
inline std::string border_width(std::string Borderwidth){ return "border-right:"+Borderwidth+";";};
inline std::string border_style(std::string Borderstyle){ return "border-right:"+Borderstyle+";";};
inline std::string border_color(std::string rgb,std::string a = "1"){ return "border-right-color:rgb("+rgb+","+a+");";};
}
namespace left {
inline std::string border(std::string borderText){return std::string{"border-left:"+borderText+";"};};
inline std::string border_width(std::string Borderwidth){ return "border-left:"+Borderwidth+";";};
inline std::string border_style(std::string Borderstyle){ return "border-left:"+Borderstyle+";";};
inline std::string border_color(std::string rgb,std::string a = "1"){ return "border-left-color:rgb("+rgb+","+a+");";};
}
namespace top {
inline std::string border(std::string borderText){return std::string{"border-top:"+borderText+";"};};
inline std::string border_width(std::string Borderwidth){ return "border-top:"+Borderwidth+";";};
inline std::string border_style(std::string Borderstyle){ return "border-top:"+Borderstyle+";";};
inline std::string border_color(std::string rgb,std::string a = "1"){return "border-top-color:rgb("+rgb+","+a+");";};
}
}


namespace Height {
inline std::string height(std::string value,std::string type = "px"){return std::string{"height:"+value+type+";"};};
}



}



#endif // INLINESTYLE_H
