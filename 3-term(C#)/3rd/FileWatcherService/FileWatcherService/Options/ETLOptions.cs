using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileWatcherService.Options
{
    public class ETLOptions : Options
    {
        public WorkFoldersOptions WorkFoldersOptions { get; set; }
        public LoggerOptions LoggerOptions { get; set; }
        public ArchivationOptions ArchivationOptions { get; set; }
        public EncryptionOptions EncryptionOptions { get; set; }

        public ETLOptions()
        {
        }

        public ETLOptions(WorkFoldersOptions workFoldersOptions, LoggerOptions loggerOptions,
            ArchivationOptions archivationOptions, EncryptionOptions encryptionOptions)
        {
            WorkFoldersOptions = workFoldersOptions;
            LoggerOptions = loggerOptions;
            ArchivationOptions = archivationOptions;
            EncryptionOptions = encryptionOptions;
        }
    }
}
