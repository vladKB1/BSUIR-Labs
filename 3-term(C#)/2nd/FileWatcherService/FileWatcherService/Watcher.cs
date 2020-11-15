﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace FileWatcherService
{
    class Watcher
    {
        FileSystemWatcher watcher;
        bool enabled = true;

        string source = @"C:\Projects\FileWatcherService\source";
        string target = @"C:\Projects\FileWatcherService\target";
        string safeArchive = @"C:\Projects\FileWatcherService\target\Archive";

        public Watcher()
        {
            Directory.CreateDirectory(source);
            Directory.CreateDirectory(target);
            Directory.CreateDirectory(safeArchive);

            watcher = new FileSystemWatcher(source);
            watcher.Created += Created;
        }

        public void Start()
        {
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
        }

        private void Created(object sender, FileSystemEventArgs e)
        {     
            string pathToFile = e.FullPath;
            DateTime date = File.GetLastWriteTime(pathToFile);
            string name = Path.GetFileNameWithoutExtension(pathToFile);
            string extansion = Path.GetExtension(pathToFile);

            if (extansion != ".gz" && extansion != "")
            {

                byte[] key, iv;
                (key, iv) = Encryption.GenKeyIv();
                File.WriteAllBytes(pathToFile, Encryption.Encrypt(pathToFile, key, iv));


                string pathToArchive = Path.Combine(source, name + ".gz");
                Archivation.Compress(pathToFile, pathToArchive);


                File.Delete(pathToFile);

                if (!Directory.Exists(safeArchive))
                {
                    Directory.CreateDirectory(safeArchive);
                }

                string newPathToArchive = Path.Combine(safeArchive, name + ".gz");
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


                File.WriteAllBytes(newPathToFile, Encryption.Decrypt(newPathToFile, key, iv));
            }                                      
        }
    }
}
    
