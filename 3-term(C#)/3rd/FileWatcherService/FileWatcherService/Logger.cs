using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using FileWatcherService.Options;

namespace FileWatcherService
{
    static class Logger
    {
        public static LoggerOptions loggerOptions;

        public static void Log(string msg)
        {               
            if (loggerOptions.NeedToLog)
            {
                string logDir = Path.GetDirectoryName(loggerOptions.LogFile);

                try
                {
                    if (!Directory.Exists(logDir))
                    {
                        Directory.CreateDirectory(logDir);
                    }
                    if (!File.Exists(loggerOptions.LogFile))
                    {
                        File.Create(loggerOptions.LogFile).Close();
                    }
                }
                catch
                {
                    loggerOptions.NeedToLog = false;
                    return;
                }


                using (StreamWriter sw = new StreamWriter(loggerOptions.LogFile, true))
                {
                    sw.WriteLine($"[{DateTime.Now:hh:mm:ss dd.MM.yyyy}] - {msg}");
                }
            }
        }
    }
}
