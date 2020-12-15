using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OptionsManager;

namespace FileManager.Options
{
    public class Validator : IValidator
    {
        public string LogString { get; private set; } = "";

        public bool MakeValidDir(string path)
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

        public bool MakeValidFile(string path)
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

        public void Validate(object obj)
        {
            ETLOptions options = obj as ETLOptions;

            WorkFoldersOptions workFoldersOptions = options.WorkFoldersOptions;
            if (!MakeValidDir(workFoldersOptions.SourceDir))
            {
                workFoldersOptions.SourceDir = @"C:\Projects\FileWatcherService\source";
                MakeValidDir(workFoldersOptions.SourceDir);

                LogString += "The access to source directory is denied, using default directory.\n";
            }
           
            if (!MakeValidDir(workFoldersOptions.TargetDir))
            {
                workFoldersOptions.TargetDir = @"C:\Projects\FileWatcherService\target";
                MakeValidDir(workFoldersOptions.TargetDir);

                LogString += "The access to target directory is denied, using default directory.\n";
            }      

            ArchivationOptions archivationOptions = options.ArchivationOptions;
            if (!MakeValidDir(archivationOptions.ArchiveDir))
            {
                archivationOptions.ArchiveDir = @"C:\Projects\FileWatcherService\target\Archive";
                MakeValidDir(archivationOptions.ArchiveDir);

                LogString += "The access to archive directory is denied, using default directory.\n";
            }

            if ((int)archivationOptions.CompressionLevel < 0 || (int)archivationOptions.CompressionLevel > 2)
            {
                archivationOptions.CompressionLevel = System.IO.Compression.CompressionLevel.Optimal;

                LogString += "Incorrect value of compression level. Default value is set.\n";
            }
        }
    }
}
