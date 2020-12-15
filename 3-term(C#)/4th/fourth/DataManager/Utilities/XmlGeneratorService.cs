using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using DataAccessLayer.DataBaseOptions;
using DataAccessLayer.Models;

namespace DataManager.Utilities
{
    public class XmlGeneratorService
    {
        SendingOptions options;

        public XmlGeneratorService(SendingOptions options)
        {
            this.options = options;
            Directory.CreateDirectory(this.options.SourceDir);
        }

        public void SerializeXML(PurchasingInfo purchasingInfo)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(PurchasingInfo));
            using (FileStream fs = new FileStream(Path.Combine(options.SourceDir,
                "purchasingInfo.xml"), FileMode.Create))
            {
                serializer.Serialize(fs, purchasingInfo);
            }
        }
    }
}
