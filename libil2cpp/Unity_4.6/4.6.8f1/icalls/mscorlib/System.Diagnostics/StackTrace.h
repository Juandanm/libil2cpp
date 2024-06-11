#pragma once

#include <stdint.h>

struct Il2CppArray;
struct Il2CppException;

namespace il2cpp
{
namespace icalls
{
namespace mscorlib
{
namespace System
{
namespace Diagnostics
{

class StackTrace
{
public:
	static Il2CppArray* get_trace(Il2CppException *exc, int32_t skip, bool need_file_info);
};

} /* namespace Diagnostics */
} /* namespace System */
} /* namespace mscorlib */
} /* namespace icalls */
} /* namespace il2cpp */
