﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileManager.Options
{
    public class EncryptionOptions : Options
    {
        public bool NeedToEncrypt { get; set; } = true;

        public EncryptionOptions()
        {
        }
    }
}
