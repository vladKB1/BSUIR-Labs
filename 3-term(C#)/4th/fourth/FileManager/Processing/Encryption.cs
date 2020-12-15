using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.IO;

namespace FileManager.Processing
{
    static class Encryption
    {

        public static (byte[], byte[]) GenKeyIv()
        {
            using (Aes aes = Aes.Create())
            {
                return (aes.Key, aes.IV);
            }
        }        

        public static byte[] Encrypt(string src, byte[] key, byte[] iv)
        {
            byte[] notEncrypted = File.ReadAllBytes(src);
            byte[] encrypted;
           
            using (Aes aes = Aes.Create())
            {
                aes.Key = key;
                aes.IV = iv;            
                ICryptoTransform encryptor = aes.CreateEncryptor(aes.Key, aes.IV);             

                using (MemoryStream msEncrypt = new MemoryStream())
                {
                    using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                    {
                        csEncrypt.Write(notEncrypted, 0, notEncrypted.Length);
                        csEncrypt.Close();
                    }
                    encrypted = msEncrypt.ToArray();
                }
            }
            
            return encrypted;
        }

        public static byte[] Decrypt(string src, byte[] key, byte[] iv)
        {
            byte[] encrypted = File.ReadAllBytes(src);
            byte[] notEncrypted;

            using (Aes aes = Aes.Create())
            {
                aes.Key = key;
                aes.IV = iv;
                ICryptoTransform encryptor = aes.CreateDecryptor(aes.Key, aes.IV);

                using (MemoryStream msEncrypt = new MemoryStream())
                {
                    using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                    {
                        csEncrypt.Write(encrypted, 0, encrypted.Length);
                        csEncrypt.Close();
                    }
                    notEncrypted = msEncrypt.ToArray();
                }
            }

            return notEncrypted;
        }
    }
}
