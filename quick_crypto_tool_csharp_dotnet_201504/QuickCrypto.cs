using System;
using System.IO;

using Gautier.GenericCrypto;

namespace Gautier.QuickCrypto
{
	public sealed class QuickCryptoAes
	{
		public static void Main(string[] args)
		{
			if(args.Length != 3)
			{
				Console.WriteLine("3 inputs required as follows, source file path   cipher key   encrypt or decrypt");
			}
			else if(args.Length == 3)
			{
				var FileName = args[0];
				var CipherKey = args[1];
				var Operation = args[2];

				bool InputsValid = ValidateInputs(FileName, CipherKey, Operation);

				if(InputsValid)
				{
					var InputText = File.ReadAllText(FileName);
					var InputOperation = (Operation == "decrypt" ? CipherOperation.Decrypt : CipherOperation.Encrypt);

					var OutputText = SimpleSymmetricAes.ExecuteCipher(InputOperation, CipherKey, InputText);
					
					Console.Write(OutputText);
				}
			}

			return;
		}
		
		private static bool ValidateInputs(string filePath, string cipherKey, string operation)
		{
			var Valid = false;

			var OperationValid = (operation == "encrypt" || operation == "decrypt");

			if(!OperationValid)
			{
				Console.WriteLine("parameter 3 must be one of the values, encrypt or decrypt.");

				return Valid;
			}
		
			var CipherHasData = (!string.IsNullOrEmpty(cipherKey));

			if(!CipherHasData)
			{
				Console.WriteLine("parameter 2 must have a value");

				return Valid;
			}

			var FilePathValid = File.Exists(filePath);

			if(!FilePathValid)
			{
				Console.WriteLine("parameter 1 must be an actual file");

				return Valid;
			}

			return (FilePathValid && CipherHasData && OperationValid);
		}
	}
}
