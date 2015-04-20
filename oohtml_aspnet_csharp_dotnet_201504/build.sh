reset

mcs -out:gautier_oohtml.dll -noconfig -nostdlib -sdk:4.5 -nologo -warn:4 -debug:full -optimize- -codepage:utf8 -define:DEBUG -t:library -r:/usr/lib/mono/4.5/mscorlib.dll -r:/usr/lib/mono/4.5/System.dll -r:/usr/lib/mono/4.5/System.Web.dll -r:/usr/lib/mono/4.5/System.Xml.dll -r:/usr/lib/mono/4.5/System.Web.Services.dll -r:/usr/lib/mono/4.5/System.Core.dll -r:/usr/lib/mono/4.5/System.Web.Extensions.dll -r:/usr/lib/mono/4.5/System.Data.dll -r:/usr/lib/mono/4.5/Npgsql.dll ScienceBaseNode.cs ScienceBaseDbMediator.cs Global.asax.cs GenericAes.cs SimpleSymmetricAes.cs HomeBase.cs home.ashx.cs

cp --force --update --no-preserve=ownership --verbose *.dll /var/www/oohtml/bin/
cp --force --update --no-preserve=ownership --verbose *.dll.mdb /var/www/oohtml/bin/
cp --force --update --no-preserve=ownership --verbose *.ashx /var/www/oohtml
cp --force --update --no-preserve=ownership --verbose *.config /var/www/oohtml
cp --force --update --no-preserve=ownership --verbose *.asax /var/www/oohtml

