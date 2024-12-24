#ifndef LISTITEMNODB_H
#define LISTITEMNODB_H

#include <vector>

namespace MongoCore {


template <typename T>
class ListItemNoDB
{
public:
    ListItemNoDB(){}

    inline void setLimit( const int limit) { m_limit = limit; };





    virtual void onList( const std::vector<T> &mlist ) = 0;

private:
    std::vector<T> m_list;
    int m_skip{0};
    int m_limit{20};
};

}

#endif // LISTITEMNODB_H
