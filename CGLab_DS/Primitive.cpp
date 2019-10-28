#include "Primitive.h"

Primitive::Primitive(int p_num) : p_num(p_num)
{
	type = PrimitiveType::None;
	// 只有type为None的时候，才可以进行set图元操作
}
