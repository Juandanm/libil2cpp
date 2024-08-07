#include "os/c-api/il2cpp-config-platforms.h"

#if !UNITY_TINY_WITHOUT_DEBUGGER

#include "os/c-api/Debug-c-api.h"
#include "os/Debug.h"

extern "C"
{
int32_t UnityPalIsDebuggerPresent()
{
    return il2cpp::os::Debug::IsDebuggerPresent();
}
}

#endif
