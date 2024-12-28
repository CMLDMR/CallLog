#include "CDRTableItem.h"

CDRTableItem::CDRTableItem()
    :MongoCore::Item("cdr")
{

}

long long CDRTableItem::calldate() const
{
    auto val = this->element("calldate");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_int64 ) {
            return val.value().view().get_int64().value;
        }
    }
    return 0;
}

std::string CDRTableItem::clid() const
{
    auto val = this->element("clid");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::src() const
{
    auto val = this->element("src");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::dst() const
{
    auto val = this->element("dst");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::dcontext() const
{
    auto val = this->element("dcontext");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::channel() const
{
    auto val = this->element("channel");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::dstchannel() const
{
    auto val = this->element("dstchannel");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::lastapp() const
{
    auto val = this->element("lastapp");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::lastdata() const
{
    auto val = this->element("lastdata");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

int CDRTableItem::duration() const
{
    auto val = this->element("duration");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_int64 ) {
            return val.value().view().get_int64().value;
        }
    }
    return 0;
}

int CDRTableItem::billsec() const
{
    auto val = this->element("billsec");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_int64 ) {
            return val.value().view().get_int64().value;
        }
    }
    return 0;
}

std::string CDRTableItem::disposition() const
{
    auto val = this->element("disposition");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

int CDRTableItem::amaflags() const
{
    auto val = this->element("amaflags");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_int64 ) {
            return val.value().view().get_int64().value;
        }
    }
    return 0;
}

std::string CDRTableItem::accountcode() const
{
    auto val = this->element("accountcode");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::uniqueid() const
{
    auto val = this->element("uniqueid");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::userfield() const
{
    auto val = this->element("userfield");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::did() const
{
    auto val = this->element("did");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::recordingfile() const
{
    auto val = this->element("recordingfile");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::cnum() const
{
    auto val = this->element("cnum");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::cnam() const
{
    auto val = this->element("cnam");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::outbound_cnum() const
{
    auto val = this->element("outbound_cnum");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::outbound_cnam() const
{
    auto val = this->element("outbound_cnam");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::dst_cnam() const
{
    auto val = this->element("dst_cnam");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::linkedid() const
{
    auto val = this->element("linkedid");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

std::string CDRTableItem::peeraccount() const
{
    auto val = this->element("peeraccount");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_string ) {
            return val.value().view().get_string().value.data();
        }
    }
    return "";
}

int CDRTableItem::sequence() const
{
    auto val = this->element("sequence");
    if( val ) {
        if( val.value().view().type() == bsoncxx::type::k_int64 ) {
            return val.value().view().get_int64().value;
        }
    }
    return 0;
}

void CDRTableItem::setUniqueid(const std::string &uniqueid)
{
    append( "uniqueid" , uniqueid );
}
