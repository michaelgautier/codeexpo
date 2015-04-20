reset

mcs -out:QuickCryptoAes.exe -noconfig -nostdlib -sdk:4.5 -nologo -warn:4 -debug:full -optimize- -codepage:utf8 -define:DEBUG -t:exe -r:/usr/lib/mono/4.5/mscorlib.dll -r:/usr/lib/mono/4.5/System.dll -r:/usr/lib/mono/4.5/System.Core.dll GenericAes.cs SimpleSymmetricAes.cs QuickCrypto.cs


