using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataManager.Utilities;
using OptionsManager;
using DataAccessLayer;
using DataAccessLayer.Utilities;
using DataAccessLayer.DataBaseOptions;
using DataAccessLayer.Models;
using ServiceLayer;
using Logger;

namespace DataManager
{
    class Program
    {
        static void Main(string[] args)
        {
            string appDirectory = AppDomain.CurrentDomain.BaseDirectory;

            Parser.Parser parser = new Parser.Parser();
            IValidator validator = new Validator();
            OptionsManager<DataAccessOptions> options =
                new OptionsManager<DataAccessOptions>(appDirectory, parser, validator);

            LoggerOptions loggerOptions = new LoggerOptions();
            loggerOptions.ConnectionOptions = options.GetOptions<ConnectionOptions>() as ConnectionOptions;
            Logger.Logger logger = new Logger.Logger(loggerOptions);

            logger.Log(options.LogString);

            ServiceLayer.ServiceLayer SL = new ServiceLayer.ServiceLayer(
                options.GetOptions<ConnectionOptions>() as ConnectionOptions);
            SendingOptions sendingOptions = options.GetOptions<SendingOptions>() as SendingOptions;

            logger.Log("DataManager is fetching data");
            PurchasingInfo purchasingInfo = SL.GetPurchasingInfo();
            logger.Log("DataManager has fetch all data successfully!");
           
            XmlGeneratorService xmlGenerator = new XmlGeneratorService(sendingOptions);
            xmlGenerator.SerializeXML(purchasingInfo);
            logger.Log("DataManager has sent all data tp FTP server successfully!");

        }
    }
}
