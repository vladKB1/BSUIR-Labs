using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileWatcherService.Options
{
    public class ETLJsonOptions : ETLOptions
    {
        public ETLJsonOptions(string json) : base()
        {
            ETLOptions options = Parser.Parser.DeserializeJson<ETLOptions>(json);
            WorkFoldersOptions = options.WorkFoldersOptions;
            LoggerOptions = options.LoggerOptions;
            ArchivationOptions = options.ArchivationOptions;
            EncryptionOptions = options.EncryptionOptions;

            Validation.Validate(this);            
        }
    }
}
