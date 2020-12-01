using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileWatcherService.Options
{
    public class WorkFoldersOptions : Options
    {
        public string SourceDir { get; set; } = @"C:\Projects\FileWatcherService\source";
        public string TargetDir { get; set; } = @"C:\Projects\FileWatcherService\target";

        public WorkFoldersOptions()
        {
        }
    }
}
