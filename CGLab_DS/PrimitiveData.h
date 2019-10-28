#ifndef PRIMITIVEDATA_H
#define PRIMITIVEDATA_H

#include <QPen>

class PrimitiveData
{
protected:
	QPen pen_in_use; // 描述当前图元使用的画笔是什么

public:
    PrimitiveData(QPen pen);
};

#endif // PRIMITIVEDATA_H
