
#include "Bootstrap5ThemeKeys.h"

const std::string Bootstrap::Grid::xs(const int index)
{
    return "col-"+std::to_string(index)+" ";
}

const std::string Bootstrap::Grid::sm(const int index)
{
    return "col-sm-"+std::to_string(index)+" ";
}

const std::string Bootstrap::Grid::md(const int index)
{
    return "col-md-"+std::to_string(index)+" ";
}

const std::string Bootstrap::Grid::lg(const int index)
{
    return ("col-lg-"+std::to_string(index)+" ");
}

const std::string Bootstrap::Grid::xl(const int index)
{
    return "col-xl-"+std::to_string(index)+" ";
}

const std::string Bootstrap::Grid::xxl(const int index)
{
    return "col-xxl-"+std::to_string(index)+" ";
}

const std::string Bootstrap::Grid::full(const int index)
{
    return xxl(index)+xl(index)+lg(index)+md(index)+sm(index)+xs(index);
}
