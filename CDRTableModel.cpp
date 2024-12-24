#include "CDRTableModel.h"

#include <QDateTime>
#include <qdebug.h>

#include "SQLToNoSQL.h"

CDRTableModel::CDRTableModel(QObject *parent)
    : QAbstractListModel{parent}
{

    m_querier = new SQLToNoSQL( this );

    connect( m_querier , &SQLToNoSQL::readyQuery , this , &CDRTableModel::queriedModel );

    // QTimer::singleShot( 1000 , this , &CDRTableModel::queryModel );
}


int CDRTableModel::rowCount(const QModelIndex &parent) const
{
    return m_list.size();
}

QVariant CDRTableModel::data(const QModelIndex &index, int role) const
{
    if( ! index.isValid() )
        return {};

    if( index.row() >= m_list.size() )
        return {};


    if( role == Qt::DisplayRole ) {

        switch ( index.column() ) {
        case 0:
            return QDateTime::fromMSecsSinceEpoch(m_list.at(index.row()).calldate()).toString();
            break;
        case 1:
            return m_list.at(index.row()).clid().data();
            break;
        case 2:
            return m_list.at(index.row()).src().data();
            break;
        case 3:
            return m_list.at(index.row()).dst().data();
            break;
        case 4:
            return m_list.at(index.row()).dcontext().data();
            break;
        case 5:
            return m_list.at(index.row()).channel().data();
            break;
        case 6:
            return m_list.at(index.row()).dstchannel().data();
            break;
        case 7:
            return m_list.at(index.row()).lastapp().data();
            break;
        case 8:
            return m_list.at(index.row()).lastdata().data();
            break;
        case 9:
            return m_list.at(index.row()).duration();
            break;
        case 10:
            return m_list.at(index.row()).billsec();
            break;
        case 11:
            return m_list.at(index.row()).disposition().data();
            break;
        case 12:
            return m_list.at(index.row()).amaflags();
            break;
        case 13:
            return m_list.at(index.row()).accountcode().data();
            break;
        case 14:
            return m_list.at(index.row()).uniqueid().data();
            break;
        case 15:
            return m_list.at(index.row()).userfield().data();
            break;
        case 16:
            return m_list.at(index.row()).did().data();
            break;
        case 17:
            return m_list.at(index.row()).recordingfile().data();
            break;
        case 18:
            return m_list.at(index.row()).cnum().data();
            break;
        case 19:
            return m_list.at(index.row()).cnam().data();
            break;
        case 20:
            return m_list.at(index.row()).outbound_cnum().data();
            break;
        case 21:
            return m_list.at(index.row()).outbound_cnam().data();
            break;
        case 22:
            return m_list.at(index.row()).dst_cnam().data();
            break;
        case 23:
            return m_list.at(index.row()).linkedid().data();
            break;
        case 24:
            return m_list.at(index.row()).peeraccount().data();
            break;
        case 25:
            return m_list.at(index.row()).sequence();
            break;
        default:
            break;
        }
    }

    return {};
}

void CDRTableModel::updateQueryModel()
{
    m_querier->startQuery();
}

void CDRTableModel::queriedModel()
{
    if( ! m_querier->queryList().size() ) {
        return;
    }

    beginResetModel();
    m_list.clear();

    for( const auto &item : m_querier->queryList() ) {

        m_list.push_back( item );

    }

    if( m_list.size() ) {
        const auto item = m_list.front();
        m_colsName.clear();
        for( const auto element : item.view() ){
            m_colsName.push_back( element.key().data() );
        }

    }

    endResetModel();
}


int CDRTableModel::columnCount(const QModelIndex &parent) const
{
    return m_colsName.size();
}


QVariant CDRTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if( role == Qt::DisplayRole ) {

        if( orientation == Qt::Horizontal ) {
            return m_colsName.at( section );
        }
        else if ( orientation == Qt::Vertical ) {
            return QVariant(section);
        }
        else {
            return QVariant("-");
        }
    }

    return QVariant();
}
