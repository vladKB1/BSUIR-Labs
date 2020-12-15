using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using FileManager.Options;

namespace FileManager.Processing
{
    static class Archivation
    {
        public static void Compress(string src, string arhcivePath,
            ArchivationOptions archivationOptions) 
        {
            using (FileStream sourceStream = new FileStream(src, FileMode.OpenOrCreate))
            {
                using (FileStream targetStream = File.Create(arhcivePath))
                {
                    using (GZipStream compressStream = new GZipStream(targetStream,
                        archivationOptions.CompressionLevel))
                    {
                        sourceStream.CopyTo(compressStream);
                    }
                }              
            }
        }

        public static void Decompress(string arhcivePath, string target)
        {
            using (FileStream sourceStream = new FileStream(arhcivePath, FileMode.OpenOrCreate))
            {
                using (FileStream targetStream = File.Create(target))
                {
                    using (GZipStream decompressStream = new GZipStream(sourceStream, CompressionMode.Decompress))
                    {
                        decompressStream.CopyTo(targetStream);
                    }
                }
            }
        }        
    }
}
