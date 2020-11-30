using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileWatcherService.Options
{
    public class ETLXmlOptions : ETLOptions
    {
        public ETLXmlOptions(string xml) : base()
        {
            ETLOptions options = Parser.Parser.DeserializeXML<ETLOptions>(json);
            WorkFoldersOptions = options.workFoldersOptions;
            LoggerOptions = options.loggerOptions;
            ArchivationOptions = options.archivationOptions;
            EncryptionOptions = options.encryptionOptions;

            Validation.Validate(this);
        }
    }
}
