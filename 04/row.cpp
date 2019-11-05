#include "row.h"

Row::Row(const size_t n): data(nullptr), N(n)
{
    data = new int[n];
}

Row::~Row()
{
    delete data;
}

size_t Row::getColumns() const
{
    return N;
}
