using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileWatcherService
{
    static class Archivation
    {
        public static void Compress(string src, string arhcivePath)
        {
            using (FileStream sourceStream = new FileStream(src, FileMode.OpenOrCreate))
            {
                using (FileStream targetStream = File.Create(arhcivePath))
                {
                    using (GZipStream compressStream = new GZipStream(targetStream, CompressionMode.Compress))
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
