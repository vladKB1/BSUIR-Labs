using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Compression;

namespace FileManager.Options
{
    public class ArchivationOptions : Options
    {        
        public string ArchiveDir { get; set; } = @"C:\Projects\FileWatcherService\target\Archive";
        public CompressionLevel CompressionLevel { get; set; } = CompressionLevel.Optimal;        

        public ArchivationOptions()
        {
        }
    }
}
