using EasyHook;
using log4net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using CLRHandler.QQLib;

namespace CLRHandler
{
    class Hooker
    {
        public void Install()
        {
            var logger = LogManager.GetLogger(typeof(Hooker));
            logger.Debug("Install Hook");
            //LocalHook.Create(LocalHook.GetProcAddress("AppUtil", "?OpenContactChatSession@ChatSession@Util@@YAXKPAUITXData@@@Z"),
            //    new OpenContactChatSessionDelegate(Fake.OpenContactChatSession), null).ThreadACL.SetExclusiveACL(new Int32[] { 0 });
        }
    }

    static class Fake
    {
        
    }
}
