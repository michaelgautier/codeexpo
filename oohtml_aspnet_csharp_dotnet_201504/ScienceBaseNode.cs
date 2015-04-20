using Npgsql;
using NpgsqlTypes;
using System;
using System.Collections.Generic;
using System.Data;

namespace Gautier.OOHtml.Models
{
	internal sealed class ScienceBaseNode
	{
		internal ScienceBaseNode(int grpId)
		{
			_GroupId = grpId;
			
			return;
		}

		internal ScienceBaseNode(int grpId, int dbId) : this(grpId)
		{
			_RdbRowId = dbId;
			
			return;
		}

		private int _RdbRowId = int.MinValue;

		internal int RdbRowId
		{
			get
			{
				return _RdbRowId;
			}
		}

		/*Matching the Schema of the input data more or less*/
		internal bool HasChildren {get;set;}

		internal string Id {get;set;}
		internal string Rel {get;set;}
		internal string Summary {get;set;}
		internal string Title {get;set;}
		internal string Url {get;set;}

		private int _GroupId = int.MinValue;

		internal int GroupId 
		{
			get
			{
				return _GroupId;
			}
		}

		internal void Read(int grpId, KeyValuePair<string, object> input)
		{
			if(grpId == _GroupId)
			{
				switch(input.Key)
				{
					case "id":
					Id = Convert.ToString(input.Value);
					break;
					case "rel":
					Rel = Convert.ToString(input.Value);
					break;
					case "summary":
					Summary = Convert.ToString(input.Value);
					break;
					case "title":
					Title = Convert.ToString(input.Value);
					break;
					case "url":
					Url = Convert.ToString(input.Value);
					break;
					case "haschildren":
					{
						var HasChildrenValue = HasChildren;

						bool.TryParse (Convert.ToString(input.Value), out HasChildrenValue);
					
						HasChildren = HasChildrenValue;
					}
					break;
				}
			}
			else
			{
				var ErrorMessage = string.Format("group ids do not match. Group ID {0}, ID passed {1}, data: {2} {3} {4} {5} {6}", _GroupId, grpId, Id, Rel, Summary, Title, Url);
				throw new ApplicationException(ErrorMessage);
			}
			
			return;
		}
		
		internal void Read(NpgsqlDataReader reader)
		{
			if(null != reader)
			{
				var FMax = reader.FieldCount;

				for(var FIDX = 0; FIDX < FMax; FIDX++)
				{
					var FN = reader.GetName(FIDX);
					var FV = reader[FN];
				
					switch(FN)
					{
						case"id":
							_RdbRowId = Convert.ToInt32(FV);
						break;
						case"groupid":
							_GroupId = Convert.ToInt32(FV);
						break;
						case"srcid":
							Id = Convert.ToString(FV);
						break;
						case"title":
							Title = Convert.ToString(FV);
						break;
						case"relation":
							Rel = Convert.ToString(FV);
						break;
						case"haschildren":
							HasChildren = Convert.ToBoolean(FV);
						break;
						case"url":
							Url = Convert.ToString(FV);
						break;
						case"summary":
							Summary = Convert.ToString(FV);
						break;
					}
				}
			}
			
			return;
		}
		
	}
}
