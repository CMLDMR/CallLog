#ifndef TEXT_H
#define TEXT_H

#include <Wt/WText.h>
#include <Wt/WContainerWidget.h>

namespace Widget {

class Text : public Wt::WText
{
public:
    Text();
    Text( const std::string &text );
    Text( const std::string &text , Wt::TextFormat textFormat );


    void setText( const std::string &text );
    std::string text() const;
    void setTextAlignment( Wt::AlignmentFlag alignmentFlag );

    void setInline( const bool isInline );

    void setContentAlignment( const Wt::AlignmentFlag &alignment );

private:
    Wt::WText* m_text;
};

} // namespace Widget

#endif // TEXT_H
