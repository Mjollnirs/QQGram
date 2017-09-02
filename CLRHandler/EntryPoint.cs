using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Reflection;
using System.IO;
using System.Threading;
using log4net;
using log4net.Config;

namespace CLRHandler
{
    static class EntryPoint
    {
        public static int Entry(string arg)
        {
            AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;
            AppDomain.CurrentDomain.FirstChanceException += CurrentDomain_FirstChanceException;

            InitLog();

            var logger = LogManager.GetLogger(typeof(EntryPoint));

            Process process = Process.GetCurrentProcess();

            logger.InfoFormat("进入Handler，进程：{0}，{1}", process.Id, process.ProcessName);

            Hooker hooker = new Hooker();
            hooker.Install();

            return 1;
        }

        private static void CurrentDomain_FirstChanceException(object sender, System.Runtime.ExceptionServices.FirstChanceExceptionEventArgs e)
        {
            var logger = LogManager.GetLogger(typeof(EntryPoint));
            logger.Error(e.Exception);
        }

        private static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            var logger = LogManager.GetLogger(typeof(EntryPoint));
            logger.Error(e.ExceptionObject);
        }

        private static void InitLog()
        {
            var logCfg = new FileInfo(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"QQGram\log4net.xml"));
            XmlConfigurator.ConfigureAndWatch(logCfg);
        }
    }
}
