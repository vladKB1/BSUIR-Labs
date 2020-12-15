using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using FileManager.Options;

namespace FileManager.Logger
{
    public class Logger
    {
        public LoggerOptions LoggerOptions { get; set; }            

        public Logger(LoggerOptions loggerOptions)
        {
            LoggerOptions = loggerOptions;
        }

        public void Log(string msg)
        {                           
            if (LoggerOptions.NeedToLog)
            {
                string logDir = Path.GetDirectoryName(LoggerOptions.LogFile);

                try
                {
                    if (!Directory.Exists(logDir))
                    {
                        Directory.CreateDirectory(logDir);
                    }
                    if (!File.Exists(LoggerOptions.LogFile))
                    {
                        File.Create(LoggerOptions.LogFile).Close();
                    }
                }
                catch
                {
                    LoggerOptions.NeedToLog = false;
                    return;
                }
        
                using (StreamWriter sw = new StreamWriter(LoggerOptions.LogFile, true))
                {
                    sw.WriteLine($"[{DateTime.Now:hh:mm:ss dd.MM.yyyy}] - {msg}");
                }
            }
        }
    }
}
