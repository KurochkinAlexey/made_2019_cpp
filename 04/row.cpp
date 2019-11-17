#include "row.h"

Row::Row(const size_t n): N(n)
{
    for(size_t i = 0; i < N; i++)
        data.push_back(0);
}

Row::~Row()
{

}

size_t Row::getColumns() const
{
    return N;
}
