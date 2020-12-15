using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileManager.Options
{
    public class ETLOptions : Options
    {
        public WorkFoldersOptions WorkFoldersOptions { get; set; } = new WorkFoldersOptions();
        public LoggerOptions LoggerOptions { get; set; } = new LoggerOptions();
        public ArchivationOptions ArchivationOptions { get; set; } = new ArchivationOptions();
        public EncryptionOptions EncryptionOptions { get; set; } = new EncryptionOptions();

        public ETLOptions()
        {            
        }      
    }
}
