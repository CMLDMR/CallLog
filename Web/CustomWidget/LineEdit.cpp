#include "LineEdit.h"
#include "Web/CSSGenerator.h"
#include "Web/Bootstrap/Bootstrap5ThemeKeys.h"

using namespace Wt;

namespace Widget {

LineEdit::LineEdit()
{
    m_lineEdit = addNew<Wt::WLineEdit>();
    auto selector = CSSGen::createCSS( "form-control" , { {"border-radius","0px !important"} });
    m_lineEdit->addStyleClass( selector + Bootstrap::Form_Controls::Sizing::form_control_sm );


}

void Widget::LineEdit::setPlaceholderText(const std::string &placeHolderText)
{
    m_lineEdit->setPlaceholderText( placeHolderText );
}

void LineEdit::setEchoMode(const Wt::EchoMode mode)
{
    m_lineEdit->setEchoMode( mode );
}

void LineEdit::setText(const std::string &text)
{
    m_lineEdit->setText( text );
}

std::string LineEdit::text() const
{
    return m_lineEdit->text().toUTF8();
}

Wt::EventSignal<> &LineEdit::textInput()
{
    return m_lineEdit->textInput();
}

void LineEdit::setEnabled(const bool enabled)
{
    m_lineEdit->setEnabled( enabled );
}

} // namespace Widget
