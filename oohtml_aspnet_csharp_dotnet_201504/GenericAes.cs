using System;
using System.IO;
using System.Security.Cryptography;

namespace Gautier.GenericAes
{
	//Code as represented on MSDN at the following address.
	//https://msdn.microsoft.com/en-us/library/system.security.cryptography.aesmanaged(v=vs.110).aspx
	internal sealed class AesExpeditor
	{
		/*
			Typical usage:

				using (AesManaged myAes = new AesManaged())
				{
					// Encrypt the string to an array of bytes. 
					byte[] encrypted = EncryptStringToBytes_Aes(original, myAes.Key, myAes.IV);

					// Decrypt the bytes to a string. 
					string roundtrip = DecryptStringFromBytes_Aes(encrypted, myAes.Key, myAes.IV);
				}
			}
		*/

		internal static byte[] EncryptStringToBytes_Aes(string plainText, byte[] Key, byte[] IV)
		{
			// Check arguments. 
			if (plainText == null || plainText.Length <= 0)
			    throw new ArgumentNullException("plainText");
			if (Key == null || Key.Length <= 0)
			    throw new ArgumentNullException("Key");
			if (IV == null || IV.Length <= 0)
			    throw new ArgumentNullException("Key");
			byte[] encrypted;
			// Create an AesManaged object 
			// with the specified key and IV. 
			using (AesManaged aesAlg = new AesManaged())
			{
			    aesAlg.Key = Key;
			    aesAlg.IV = IV;
			    // Create a decrytor to perform the stream transform.
			    ICryptoTransform encryptor = aesAlg.CreateEncryptor(aesAlg.Key, aesAlg.IV);
			    // Create the streams used for encryption. 
			    using (MemoryStream msEncrypt = new MemoryStream())
			    {
				using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
				{
				    using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
				    {
				        //Write all data to the stream.
				        swEncrypt.Write(plainText);
				    }
				    encrypted = msEncrypt.ToArray();
				}
			    }
			}
			// Return the encrypted bytes from the memory stream. 
			return encrypted;
		}

		internal static string DecryptStringFromBytes_Aes(byte[] cipherText, byte[] Key, byte[] IV)
		{
			// Check arguments. 
			if (cipherText == null || cipherText.Length <= 0)
			    throw new ArgumentNullException("cipherText");
			if (Key == null || Key.Length <= 0)
			    throw new ArgumentNullException("Key");
			if (IV == null || IV.Length <= 0)
			    throw new ArgumentNullException("Key");
			// Declare the string used to hold 
			// the decrypted text. 
			string plaintext = null;
			// Create an AesManaged object 
			// with the specified key and IV. 
			using (AesManaged aesAlg = new AesManaged())
			{
			    aesAlg.Key = Key;
			    aesAlg.IV = IV;
			    // Create a decrytor to perform the stream transform.
			    ICryptoTransform decryptor = aesAlg.CreateDecryptor(aesAlg.Key, aesAlg.IV);
			    // Create the streams used for decryption. 
			    using (MemoryStream msDecrypt = new MemoryStream(cipherText))
			    {
				using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
				{
				    using (StreamReader srDecrypt = new StreamReader(csDecrypt))
				    {
				        // Read the decrypted bytes from the decrypting stream 
				        // and place them in a string.
				        plaintext = srDecrypt.ReadToEnd();
				    }
				}
			    }
			}
			return plaintext;
		}
	}
}

