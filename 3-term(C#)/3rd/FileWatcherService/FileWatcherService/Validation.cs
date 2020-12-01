using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using FileWatcherService.Options;

namespace FileWatcherService
{
    public static class Validation
    {
        public static bool MakeValidDir(string path)
        {
            if (!Directory.Exists(path))
            {
                try
                {
                    Directory.CreateDirectory(path);
                }
                catch
                {
                    return false;
                }
            }

            return true;
        }

        public static bool MakeValidFile(string path)
        {
            if (!File.Exists(path))
            {
                if (!MakeValidDir(Path.GetDirectoryName(path)))
                {
                    return false;
                }

                try
                {
                    File.Create(path).Close();
                }
                catch
                {
                    return false;
                }
            }

            return true;            
        }

        public static void Validate(ETLOptions options)
        {
            WorkFoldersOptions workFoldersOptions = options.WorkFoldersOptions;
            if (!MakeValidDir(workFoldersOptions.SourceDir))
            {
                workFoldersOptions.SourceDir = @"C:\Projects\FileWatcherService\source";
                MakeValidDir(workFoldersOptions.SourceDir);

                Logger.Log("The access to source directory is denied, using default directory.");
            }
           
            if (!MakeValidDir(workFoldersOptions.TargetDir))
            {
                workFoldersOptions.TargetDir = @"C:\Projects\FileWatcherService\target";
                MakeValidDir(workFoldersOptions.TargetDir);

                Logger.Log("The access to target directory is denied, using default directory.");
            }


            LoggerOptions loggerOptions = options.LoggerOptions;
            if (!MakeValidFile(loggerOptions.LogFile))
            {
                loggerOptions.LogFile = @"C:\Projects\FileWatcherService\log.txt";
                MakeValidFile(loggerOptions.LogFile);

                Logger.Log("The access to log file is denied, using default log file.");
            }


            ArchivationOptions archivationOptions = options.ArchivationOptions;
            if (!MakeValidDir(archivationOptions.ArchiveDir))
            {
                archivationOptions.ArchiveDir = @"C:\Projects\FileWatcherService\target\Archive";
                MakeValidDir(archivationOptions.ArchiveDir);

                Logger.Log("The access to archive directory is denied, using default directory.");
            }

            if ((int)archivationOptions.CompressionLevel < 0 || (int)archivationOptions.CompressionLevel > 2)
            {
                archivationOptions.CompressionLevel = System.IO.Compression.CompressionLevel.Optimal;
                
                Logger.Log("Incorrect value of compression level. Default value is set.");
            }
        }
    }
}
