#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>

namespace Widget {

class ComboBox : public Wt::WContainerWidget
{
public:
    ComboBox();

    void addItem( const std::string &item );
    void addItems( const std::vector<std::string> &itemList );
    int count() const;
    int currentIndex() const;
    std::string currentText() const;
    void setCurrentIndex( const int index );

    void setEnabled( const bool enabled );

    ///
    /// \brief itemText
    /// \param index
    /// \return selected index item as a std::string
    ///
    std::string itemText( const int index ) const;

    ///
    /// \brief activated
    /// \return index of selected
    ///
    Wt::Signal<int> &activated();

    ///
    /// \brief sactivated
    /// \return selected item as a string
    ///
    Wt::Signal<Wt::WString> &sactivated();

private:
    Wt::WComboBox* m_comboBox;
};

} // namespace Widget

#endif // COMBOBOX_H
