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
             ETLOptions options = Parser.Parser.DeserializeXML<ETLOptions>(xml);
             WorkFoldersOptions = options.WorkFoldersOptions;
             LoggerOptions = options.LoggerOptions;
             ArchivationOptions = options.ArchivationOptions;
             EncryptionOptions = options.EncryptionOptions;
             
            Validation.Validate(this);                     
        }
    }
}
