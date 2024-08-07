#include "il2cpp-config.h"
#include "class-internals.h"
#include "Il2CppTypeCompare.h"
#include <cassert>

namespace il2cpp
{
namespace metadata
{

bool Il2CppTypeCompare::operator() (const KeyWrapper<const Il2CppType*>& t1, const KeyWrapper<const Il2CppType*>& t2) const
{
	return Compare (t1, t2);
}

bool Il2CppTypeCompare::Compare (const KeyWrapper<const Il2CppType*>& t1, const KeyWrapper<const Il2CppType*>& t2)
{
	if (t1.type != t2.type)
		return false;
	else if (!t1.isNormal())
		return true;

	if ((t1.key->type != t2.key->type) ||
		(t1.key->byref != t2.key->byref))
		return false;

	switch (t1.key->type) {
	case IL2CPP_TYPE_VOID:
	case IL2CPP_TYPE_BOOLEAN:
	case IL2CPP_TYPE_CHAR:
	case IL2CPP_TYPE_I1:
	case IL2CPP_TYPE_U1:
	case IL2CPP_TYPE_I2:
	case IL2CPP_TYPE_U2:
	case IL2CPP_TYPE_I4:
	case IL2CPP_TYPE_U4:
	case IL2CPP_TYPE_I8:
	case IL2CPP_TYPE_U8:
	case IL2CPP_TYPE_R4:
	case IL2CPP_TYPE_R8:
	case IL2CPP_TYPE_STRING:
	case IL2CPP_TYPE_I:
	case IL2CPP_TYPE_U:
	case IL2CPP_TYPE_OBJECT:
	case IL2CPP_TYPE_TYPEDBYREF:
		return true;
	case IL2CPP_TYPE_VALUETYPE:
	case IL2CPP_TYPE_CLASS:
		return t1.key->data.klassIndex == t2.key->data.klassIndex;
	case IL2CPP_TYPE_PTR:
	case IL2CPP_TYPE_SZARRAY:
		return Compare (t1.key->data.type, t2.key->data.type);
	case IL2CPP_TYPE_ARRAY:
		if (t1.key->data.array->rank != t2.key->data.array->rank)
			return false;
		return Compare (t1.key->data.array->etype, t2.key->data.array->etype);
	case IL2CPP_TYPE_GENERICINST: {
		const Il2CppGenericInst *i1 = t1.key->data.generic_class->context.class_inst;
		const Il2CppGenericInst *i2 = t2.key->data.generic_class->context.class_inst;
		if (i1->type_argc != i2->type_argc)
			return false;
		if (t1.key->data.generic_class->typeDefinitionIndex != t2.key->data.generic_class->typeDefinitionIndex)
			return false;
		/* FIXME: we should probably just compare the instance pointers directly.  */
		for (uint32_t i = 0; i < i1->type_argc; ++i) {
			if (!Compare (i1->type_argv[i], i2->type_argv[i]))
				return false;
		}
		return true;
	}
	case IL2CPP_TYPE_VAR:
	case IL2CPP_TYPE_MVAR:
		return t1.key->data.genericParameterIndex == t2.key->data.genericParameterIndex;
	default:
		NOT_IMPLEMENTED (Il2CppTypeCompare::compare);
		return false;
	}

	return false;
}

} /* namespace vm */
} /* namespace il2cpp */
