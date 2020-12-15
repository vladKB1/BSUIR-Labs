using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using FileManager.Options;
using FileManager.Processing;

namespace FileManager
{
    class FileManager
    {
        bool enabled = true;

        FileSystemWatcher watcher;
        Logger.Logger logger;
        OptionsManager.OptionsManager<ETLOptions> optionsManager;
        Validator validator;
        Parser.Parser parser;       

        string source = "";
        string target = "";
        string saveArchive = "";               

        public FileManager()
        {             
            string appDirectory = AppDomain.CurrentDomain.BaseDirectory;
            validator = new Validator();
            parser = new Parser.Parser();
            optionsManager = 
                new OptionsManager.OptionsManager<ETLOptions>(appDirectory, parser, validator);
            ETLOptions options = optionsManager.GetOptions<ETLOptions>() as ETLOptions;

            source = options.WorkFoldersOptions.SourceDir;
            target = options.WorkFoldersOptions.TargetDir;
            saveArchive = options.ArchivationOptions.ArchiveDir;

            logger = new Logger.Logger(optionsManager.GetOptions<Logger.LoggerOptions>()
                as Logger.LoggerOptions);
            logger.Log(optionsManager.LogString);                       

            watcher = new FileSystemWatcher(source);
            watcher.Created += Created;           
        }

        public void Start()
        {
            logger.Log("FileManager started to work.");
            watcher.EnableRaisingEvents = true;
            while (enabled)
            {
                Thread.Sleep(1000);
            }            
        }

        public void Stop()
        {
            watcher.EnableRaisingEvents = false;
            enabled = false;
            logger.Log("FileManager stoped to work.");
        }

        private void Created(object sender, FileSystemEventArgs e)
        {     
            string pathToFile = e.FullPath;
            DateTime date = File.GetLastWriteTime(pathToFile);
            string name = Path.GetFileNameWithoutExtension(pathToFile);
            string extansion = Path.GetExtension(pathToFile);

            EncryptionOptions encryptionOptions = 
                optionsManager.GetOptions<EncryptionOptions>() as EncryptionOptions;
            ArchivationOptions archivationOptions =
                optionsManager.GetOptions<ArchivationOptions>() as ArchivationOptions;


            if (extansion != ".gz" && extansion != "")
            {
                byte[] key, iv;
                (key, iv) = Encryption.GenKeyIv();

                if (encryptionOptions.NeedToEncrypt)
                {                    
                    File.WriteAllBytes(pathToFile, Encryption.Encrypt(pathToFile, key, iv));
                }
                
                string pathToArchive = Path.Combine(source, name + ".gz");
                Archivation.Compress(pathToFile, pathToArchive, archivationOptions);


                File.Delete(pathToFile);

                if (!Directory.Exists(saveArchive))
                {
                    Directory.CreateDirectory(saveArchive);
                }

                string newPathToArchive = Path.Combine(saveArchive, name + ".gz");
                if (File.Exists(newPathToArchive))
                {
                    File.Delete(newPathToArchive);
                }
                File.Move(pathToArchive, newPathToArchive);


                string newPathToFile = Path.Combine(target, date.Year.ToString(),
                    date.Month.ToString(), date.Day.ToString());
                Directory.CreateDirectory(newPathToFile);

                newPathToFile = Path.Combine(newPathToFile, name + "_"
                    + DateTime.Now.ToString("yyyy_MM_dd_hh_mm_ss") + extansion);
                Archivation.Decompress(newPathToArchive, newPathToFile);

                if (encryptionOptions.NeedToEncrypt)
                {
                    File.WriteAllBytes(newPathToFile, Encryption.Decrypt(newPathToFile, key, iv));
                }
            }                                      
        }
    }
}
    
