using Gautier.GenericCrypto;
using Gautier.OOHtml.Models;

using Npgsql;
using NpgsqlTypes;

using System;
using System.Collections.Generic;
using System.Data;

namespace Gautier.OOHtml.Data
{
	internal class ScienceBaseDbMediator
	{
		private static NpgsqlConnection CreateConnection()
		{
			var AccessKey = SimpleSymmetricAes.ExecuteCipher(CipherOperation.Decrypt, Gautier.OOHtml.Global.WebAccountDbKey, Gautier.OOHtml.Global.WebAccountUKey);
			var AccessText = string.Format("Server=127.0.0.1;Port=5432;User Id={0};Password={1};Database=translation_store;", Gautier.OOHtml.Global.WebAccountUser, AccessKey);

			var ServerConnection = new NpgsqlConnection(AccessText);

			return ServerConnection;		
		}
		

		public List<ScienceBaseNode> GetNodes()
		{
			var DataNodes = new List<ScienceBaseNode>();

			using(var ServerConnection = CreateConnection())
			{
				ServerConnection.Open();

				var ServerCommand = ServerConnection.CreateCommand();
			
				using(ServerCommand)
				{
					ServerCommand.CommandText = "select * from sciencebase order by groupid, title, url";
			
					var RowReader = ServerCommand.ExecuteReader();

					using(RowReader)
					{
						while(RowReader.Read())
						{
							var CurrentNode = new ScienceBaseNode(0);
							
							CurrentNode.Read(RowReader);
							
							DataNodes.Add(CurrentNode);
						}
					}
				}
			}

			return DataNodes;
		}
		
		public void UpdateNodes(List<ScienceBaseNode> dataNodes)
		{
			using(var ServerConnection = CreateConnection())
			{
				ServerConnection.Open();

				foreach(var DataNode in dataNodes)
				{
					UpdateNode(ServerConnection, DataNode);
				}
			}

			return;
		}
		
		private void UpdateNode(NpgsqlConnection serverConnection, ScienceBaseNode data)
		{
			var ServerCommand = serverConnection.CreateCommand();
			
			using(ServerCommand)
			{
				var CommandText = string.Empty;

				if(data.RdbRowId < 0)
				{
					CommandText = "insert into sciencebase (srcid, groupid, title, relation, haschildren, url, summary) values (@srcid, @groupid, @title, @relation, @haschildren, @url, @summary)";
				}
				else
				{
					CommandText = "update sciencebase set @srcid, @groupid, @title, @relation, @haschildren, @url, @summary where id = @id";

					var CurrentParameter = new NpgsqlParameter();
					CurrentParameter.ParameterName = "@id";
					CurrentParameter.Value = data.RdbRowId;
					CurrentParameter.NpgsqlDbType = NpgsqlDbType.Bigint;
					CurrentParameter.IsNullable = false;

					ServerCommand.Parameters.Add(CurrentParameter);
					
				}
			
				ServerCommand.CommandText = CommandText;

				AddParameters(ServerCommand, data);
				
				ServerCommand.ExecuteNonQuery();
			}
			
			return;
		}
		
		private void AddParameters(NpgsqlCommand serverCommand, ScienceBaseNode data)
		{
			var CurrentParameter = new NpgsqlParameter();
			CurrentParameter.ParameterName = "@srcid";
			CurrentParameter.Value = data.Id;
			CurrentParameter.NpgsqlDbType = NpgsqlDbType.Varchar;
			CurrentParameter.Size = 32;
			CurrentParameter.IsNullable = true;

			serverCommand.Parameters.Add(CurrentParameter);

			CurrentParameter = new NpgsqlParameter();
			CurrentParameter.ParameterName = "@groupid";
			CurrentParameter.Value = data.GroupId;
			CurrentParameter.NpgsqlDbType = NpgsqlDbType.Integer;
			CurrentParameter.IsNullable = false;

			serverCommand.Parameters.Add(CurrentParameter);

			CurrentParameter = new NpgsqlParameter();
			CurrentParameter.ParameterName = "@title";
			CurrentParameter.Value = data.Title;
			CurrentParameter.NpgsqlDbType = NpgsqlDbType.Varchar;
			CurrentParameter.Size = 128;
			CurrentParameter.IsNullable = true;

			serverCommand.Parameters.Add(CurrentParameter);

			CurrentParameter = new NpgsqlParameter();
			CurrentParameter.ParameterName = "@relation";
			CurrentParameter.Value = data.Rel;
			CurrentParameter.NpgsqlDbType = NpgsqlDbType.Varchar;
			CurrentParameter.Size = 12;
			CurrentParameter.IsNullable = true;

			serverCommand.Parameters.Add(CurrentParameter);

			CurrentParameter = new NpgsqlParameter();
			CurrentParameter.ParameterName = "@haschildren";
			CurrentParameter.Value = data.HasChildren;
			CurrentParameter.NpgsqlDbType = NpgsqlDbType.Boolean;
			CurrentParameter.IsNullable = false;

			serverCommand.Parameters.Add(CurrentParameter);

			CurrentParameter = new NpgsqlParameter();
			CurrentParameter.ParameterName = "@url";
			CurrentParameter.Value = data.Url;
			CurrentParameter.NpgsqlDbType = NpgsqlDbType.Text;
			CurrentParameter.IsNullable = true;

			serverCommand.Parameters.Add(CurrentParameter);

			CurrentParameter = new NpgsqlParameter();
			CurrentParameter.ParameterName = "@summary";
			CurrentParameter.Value = data.Summary;
			CurrentParameter.NpgsqlDbType = NpgsqlDbType.Text;
			CurrentParameter.IsNullable = true;

			serverCommand.Parameters.Add(CurrentParameter);

			return;
			
		}
	}
}
