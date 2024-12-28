#ifndef CDRTABLEITEM_H
#define CDRTABLEITEM_H

#include "MongoCoreItem/item.h"

class CDRTableItem : public MongoCore::Item
{
public:
    CDRTableItem();


    void setSQLData( const std::string &val , std::string &colName );



    long long calldate() const;
    std::string clid() const;
    std::string src() const;
    std::string dst() const;
    std::string dcontext() const;
    std::string channel() const;
    std::string dstchannel() const;
    std::string lastapp() const;
    std::string lastdata() const;
    int duration() const;
    int billsec() const;
    std::string disposition() const;
    int amaflags() const;
    std::string accountcode() const;
    std::string uniqueid() const;
    std::string userfield() const;
    std::string did() const;
    std::string recordingfile() const;
    std::string cnum() const;
    std::string cnam() const;
    std::string outbound_cnum() const;
    std::string outbound_cnam() const;
    std::string dst_cnam() const;
    std::string linkedid() const;
    std::string peeraccount() const;
    int sequence() const;


    void setUniqueid( const std::string &uniqueid );

};

#endif // CDRTABLEITEM_H
