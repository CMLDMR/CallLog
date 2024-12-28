#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <Wt/WLineEdit.h>
#include <Wt/WContainerWidget.h>

#include "Theme.h"

namespace Widget {

class LineEdit : public Wt::WContainerWidget , public Theme
{
public:
    LineEdit();

    void setPlaceholderText( const std::string &placeHolderText );
    void setEchoMode( const Wt::EchoMode mode );
    void setText( const std::string &text );

    std::string text() const;

    Wt::EventSignal<>& textInput();

    void setEnabled( const bool enabled );

private:
    Wt::WLineEdit* m_lineEdit;
};

} // namespace Widget

#endif // LINEEDIT_H
