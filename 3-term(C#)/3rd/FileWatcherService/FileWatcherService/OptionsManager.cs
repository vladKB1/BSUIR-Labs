using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using FileWatcherService.Options;

namespace FileWatcherService
{
    class OptionsManager
    {
        ETLOptions defaultOptions;
        ETLJsonOptions jsonOptions;
        ETLXmlOptions xmlOptions;
        

        bool isJsonConfigured = false;
        bool isXmlConfigured = false;

        public OptionsManager(string path)
        {
            string options;

            try
            {
                using (StreamReader sr = new StreamReader($"{path}\\appsettings.json"))
                {
                    options = sr.ReadToEnd();
                }
                
                jsonOptions = new ETLJsonOptions(options);
                isJsonConfigured = true;
                Logger.Log("appsettings.json is loaded."); 
            }
            catch (Exception ex)
            {
                isJsonConfigured = false;
                Logger.Log(ex.Message);
            }

            try
            {
                using (StreamReader sr = new StreamReader($"{path}\\config.xml"))
                {
                    options = sr.ReadToEnd();
                }

                xmlOptions = new ETLXmlOptions(options);
                isXmlConfigured = true;
                Logger.Log("config.xml is loaded.");
            }
            catch (Exception ex)
            {
                isXmlConfigured = false;
                Logger.Log(ex.Message);
            }

            if (!isJsonConfigured && !isXmlConfigured)
            {
                defaultOptions = new ETLOptions();
                Logger.Log("Default options is used.");
            }                        
        }

        Options.Options FindOption<T>(ETLOptions options)
        {
            if (typeof(T) == typeof(ETLOptions))
            {
                return options;
            }
            
            try
            {
                return options.GetType().GetProperty(typeof(T).Name).GetValue(options, null) as Options.Options;
            }
            catch
            {
                Logger.Log("FindOption didn't find the needed option and throw a NotImplementedException."); 
                throw new NotImplementedException();
            }
        }

        public Options.Options GetOptions<T>()
        {
            if (isJsonConfigured)
            {
                Logger.Log("Json configuration will be used.");
                return FindOption<T>(jsonOptions);
            }
            else if (isXmlConfigured)
            {
                Logger.Log("Json configuration is invalid or out.");
                Logger.Log("XML configuration will be used.");
                return FindOption<T>(xmlOptions);
            }
            else
            {
                Logger.Log("XML configuration is invalid or out.");
                Logger.Log("Default configuration will be used.");
                return FindOption<T>(defaultOptions);
            }
        }
    }
}
