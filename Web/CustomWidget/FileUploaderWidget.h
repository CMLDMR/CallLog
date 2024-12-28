#ifndef FILEUPLOADERWIDGET_H
#define FILEUPLOADERWIDGET_H

#include "ContainerWidget.h"
#include <Wt/WSignal.h>
#include <Wt/WFileUpload.h>

#include <QObject>

namespace Widget {

class FileUploaderWidget : public ContainerWidget /*, public DBClass*/
{
public:
    explicit FileUploaderWidget( const std::string &title = QObject::tr("Upload File").toStdString() );

    /**
     * @brief isUploaded: Check file is Uploaded
     * @return
     */
    bool isUploaded() const;

    /**
     * @brief The FilterType enum: Selectable File Type
     */
    enum FilterType{
        Pdf,
        Image,
        Zip
    };

    /**
     * @brief setType: File Type
     * @param type: Pdf , Image
     */
    void setType( FilterType type );

    /**
     * @brief fileLocation: Location is FULL PATH
     * @return
     */
    QString fileLocation() const;

    /**
     * @brief doocRootLocation: Location is Without docroot folder
     * @return
     */
    QString doocRootLocation() const;

    /**
     * @brief Uploaded: Signal Triggered When File Uploaded
     * @return
     */
    Wt::Signal<Wt::NoClass> &Uploaded();


    Wt::Signal<std::string> &errorOccured();

private:
    Wt::WFileUpload* mFileUploader;

    QString mFileLocation;
    QString mDoocRootLocation;

    bool mIsUploaded;

    Wt::Signal<Wt::NoClass> _Uploaded;

    Wt::Signal<std::string> m_errorOccured;


    FilterType mType;
};

} // namespace Widget

#endif // FILEUPLOADERWIDGET_H
