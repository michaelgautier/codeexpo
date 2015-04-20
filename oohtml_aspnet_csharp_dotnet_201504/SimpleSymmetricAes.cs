using System;
using System.Collections.Generic;
using System.Security.Cryptography;

using Gautier.GenericAes;

namespace Gautier.GenericCrypto
{
	public enum CipherOperation
	{
		Encrypt = 0,
		Decrypt
	}

	public static class SimpleSymmetricAes
	{
		public static string ExecuteCipher(CipherOperation operation, string inputkey, string inputtext)
		{
			var CipherResult = string.Empty;
			
			var KeyByteList = new List<byte>(System.Text.Encoding.UTF8.GetBytes(inputkey));

			using (var CryptoEngine = new AesManaged())
			{
				var AesKey = new byte[CryptoEngine.Key.Length];

				KeyByteList.CopyTo(0, AesKey, 0, CryptoEngine.Key.Length);
			
				KeyByteList.Sort();

				var AesIV = new byte[CryptoEngine.IV.Length];

				KeyByteList.CopyTo(0, AesIV, 0, CryptoEngine.IV.Length);

				if(operation == CipherOperation.Encrypt)
				{
					var ResultBytes = AesExpeditor.EncryptStringToBytes_Aes(inputtext, AesKey, AesIV);
				
					CipherResult = Convert.ToBase64String(ResultBytes);
				}
				else if(operation == CipherOperation.Decrypt)
				{
					var InputBytes = Convert.FromBase64String(inputtext);
				
					CipherResult = AesExpeditor.DecryptStringFromBytes_Aes(InputBytes, AesKey, AesIV);
				}
			}

			return CipherResult;
		}
	}
}
