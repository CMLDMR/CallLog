#include "FileUploaderWidget.h"
#include "Web/Bootstrap/inlinestyle.h"

#include "PushButton.h"

#include <Wt/WProgressBar.h>


#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QUuid>

using namespace Wt;

namespace Widget {

FileUploaderWidget::FileUploaderWidget(const std::string &title)
{

    mIsUploaded = false;

    auto fileUploaderContainer = this->addWidget(std::make_unique<WContainerWidget>());

    fileUploaderContainer->setMargin(10,Side::Top|Side::Bottom);

    const int maxFileSize = 6 * 1024;

    mFileUploader = fileUploaderContainer->addWidget( std::make_unique<WFileUpload>() );
    auto progresBar = fileUploaderContainer->addWidget( std::make_unique<WProgressBar>() );
    mFileUploader->setFileTextSize( maxFileSize ); // Set the maximum file size to 2048 kB.
    mFileUploader->setMargin(10, Wt::Side::Right);
    mFileUploader->setFilters("application/pdf");
    mFileUploader->setMultiple(false);
    mFileUploader->setProgressBar(progresBar);

    mFileUploader->fileTooLarge().connect([=, this] {
        // m_errorOccured( QObject::tr("File size must lower then %1").arg( DauCore::Utility::humanReadableBytes(maxFileSize).data()).toStdString() );
    });

    auto *uploadButton = fileUploaderContainer->addWidget( std::make_unique<Widget::PushButton>( title ) );
    uploadButton->setMargin(10, Wt::Side::Left | Wt::Side::Right);

    uploadButton->clicked().connect([=, this] {
        mFileUploader->progressBar()->setValue(0);
        mFileUploader->upload();
        mFileUploader->enable();
        mFileUploader->setHidden(false);
    });

    mFileUploader->uploaded().connect([=, this] {


        auto list = mFileUploader->uploadedFiles();

        // LOG_TRACE_L3("file Uploaded: {} file" , list.size() );

        if( ! list.size() ) {
            m_errorOccured( QObject::tr("Something uploaded but this is not file").toStdString() );
            return;
        }

        for( const auto &item : list )
        {
            QFileInfo info(item.clientFileName().c_str());

            QString _fileName = QString("%1-%2.%3").arg(QDateTime::currentMSecsSinceEpoch()).arg(item.clientFileName().c_str()).arg(info.suffix());

            mFileLocation = QString("docroot/tempfile/")+_fileName;
            mDoocRootLocation = QString("tempfile/")+ _fileName;
            QDir dir;
            if( dir.exists("docroot") ) {
                if( dir.cd("docroot") ) {
                    if ( ! dir.exists("tempfile") ) {
                        dir.mkdir( "tempfile" );
                    }
                }
            }

            if( QFile::copy(item.spoolFileName().c_str(),mFileLocation) )
            {
                mIsUploaded = true;
                _Uploaded.emit(NoClass());
            }else{
                mIsUploaded = false;
                m_errorOccured( QObject::tr("Can not spool file,\nSrc: %1 ,\nDst: %2, \nFile Exist: %3 ")
                                   .arg( item.spoolFileName().c_str() )
                                   .arg( mFileLocation )
                                   .arg(QFile::exists(item.spoolFileName().c_str())).toStdString() );
            }
        }

    });
}

bool FileUploaderWidget::isUploaded() const
{
    return mIsUploaded;
}

void FileUploaderWidget::setType(FileUploaderWidget::FilterType type)
{
    mType = type;

    switch (mType) {
    case Pdf:
        mFileUploader->setFilters ("application/pdf");
        break;
    case Image:
        mFileUploader->setFilters ("image/*");
        break;
    case Zip:
        mFileUploader->setFilters ("application/x-zip");
        break;
    default:
        break;
    }
}

QString FileUploaderWidget::fileLocation() const
{
    return mFileLocation;
}

QString FileUploaderWidget::doocRootLocation() const
{
    return mDoocRootLocation;
}

Wt::Signal<std::string> &FileUploaderWidget::errorOccured()
{
    return m_errorOccured;
}

Signal<NoClass> &FileUploaderWidget::Uploaded()
{
    return _Uploaded;
}

} // namespace Widget
