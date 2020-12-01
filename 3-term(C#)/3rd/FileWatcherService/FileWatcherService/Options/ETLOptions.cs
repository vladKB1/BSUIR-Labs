using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileWatcherService.Options
{
    public class ETLOptions : Options
    {
        public WorkFoldersOptions WorkFoldersOptions { get; set; } = new WorkFoldersOptions();
        public LoggerOptions LoggerOptions { get; set; } = new LoggerOptions();
        public ArchivationOptions ArchivationOptions { get; set; } = new ArchivationOptions();
        public EncryptionOptions EncryptionOptions { get; set; } = new EncryptionOptions();

        public ETLOptions()
        {
            Validation.Validate(this);
        }

        public ETLOptions(WorkFoldersOptions workFoldersOptions, LoggerOptions loggerOptions,
            ArchivationOptions archivationOptions, EncryptionOptions encryptionOptions)
        {
            WorkFoldersOptions = workFoldersOptions;
            LoggerOptions = loggerOptions;
            ArchivationOptions = archivationOptions;
            EncryptionOptions = encryptionOptions;
            Validation.Validate(this);
        }
    }
}
