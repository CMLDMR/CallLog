#include "ComboBox.h"
#include "Web/CSSGenerator.h"
#include "Web/Bootstrap/Bootstrap5ThemeKeys.h"

namespace Widget {

ComboBox::ComboBox()
{
    m_comboBox = addNew<Wt::WComboBox>();
    auto selector = CSSGen::createCSS( "form-select" , { {"border-radius","0px !important"} });
    auto selector2 = CSSGen::createCSS( "form-control-sm" , { {"padding","4px 0px !important"} });
    m_comboBox->addStyleClass( selector + " " + selector2  + " " + Bootstrap::Form_Controls::Sizing::form_control_sm );




    //padding
}

void ComboBox::addItem(const std::string &item)
{
    m_comboBox->addItem(item);
}

void ComboBox::addItems(const std::vector<std::string> &itemList)
{
    for( const auto &item : itemList ) {
        this->addItem( item );
    }
}

int ComboBox::count() const
{
    return m_comboBox->count();
}

int ComboBox::currentIndex() const
{
    return m_comboBox->currentIndex();
}

std::string ComboBox::currentText() const
{
    return m_comboBox->currentText().toUTF8();
}

void ComboBox::setCurrentIndex(const int index)
{
    m_comboBox->setCurrentIndex( index );
}

void ComboBox::setEnabled(const bool enabled)
{
    m_comboBox->setEnabled( enabled );
}

std::string ComboBox::itemText(const int index) const
{
    if( index >= 0 && index < m_comboBox->count() ) {
        return m_comboBox->itemText( index ).toUTF8();
    }
    return "";
}

Wt::Signal<int> &ComboBox::activated()
{
    return m_comboBox->activated();
}

Wt::Signal<Wt::WString> &ComboBox::sactivated()
{
    return m_comboBox->sactivated();
}

} // namespace Widget
