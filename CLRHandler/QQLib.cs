using System;
using System.Runtime.InteropServices;

namespace CLRHandler
{
    namespace QQLib
    {

        [UnmanagedFunctionPointer(CallingConvention.StdCall, SetLastError = true)]
        delegate void OpenContactChatSessionDelegate(ulong id, [MarshalAs(UnmanagedType.IUnknown)]object data);

        [UnmanagedFunctionPointer(CallingConvention.StdCall, SetLastError = true)]
        delegate ulong GetSelfUinDelegate();
    }
}
