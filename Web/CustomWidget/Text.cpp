#include "Text.h"

#include <Wt/WVBoxLayout.h>

#include <Wt/WText.h>

using namespace Wt;

namespace Widget {

Text::Text()
    :Wt::WText("")
{
    // auto vLayout = setLayout( std::make_unique<Wt::WVBoxLayout>());
    // m_text = vLayout->addWidget( std::make_unique<Wt::WText>());
    setMargin( Wt::WLength::Auto , Side::Top | Side::Bottom );
}

Text::Text(const std::string &text)
    :Wt::WText(text)
{
    // auto vLayout = setLayout( std::make_unique<Wt::WVBoxLayout>());
    // m_text = vLayout->addWidget( std::make_unique<Wt::WText>( text ));
    setMargin( Wt::WLength::Auto , Side::Top | Side::Bottom );

}

Text::Text(const std::string &text, Wt::TextFormat textFormat)
    :Wt::WText( text ,textFormat )
{
    // auto vLayout = setLayout( std::make_unique<Wt::WVBoxLayout>());
    // m_text = vLayout->addWidget( std::make_unique<Wt::WText>( text , textFormat));
    setMargin( Wt::WLength::Auto , Side::Top | Side::Bottom );

}

void Text::setText(const std::string &text)
{
    WText::setText( text );
}

std::string Text::text() const
{
    return this->WText::text().toUTF8();
}

void Text::setTextAlignment(Wt::AlignmentFlag alignmentFlag)
{
    WText::setTextAlignment( alignmentFlag );
}

void Text::setInline(const bool isInline)
{
    WText::setInline( isInline );
}

void Text::setContentAlignment(const Wt::AlignmentFlag &alignment)
{
    WText::setTextAlignment( alignment );
}

} // namespace Widget
