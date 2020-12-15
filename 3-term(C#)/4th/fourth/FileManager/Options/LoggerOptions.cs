using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileManager.Options
{
    public class LoggerOptions : Options
    {
        public bool NeedToLog { get; set; } = true;
        public string LogFile { get; set; } = @"C:\Projects\FileWatcherService\log.txt";

        public LoggerOptions()
        {
        }
    }
}
