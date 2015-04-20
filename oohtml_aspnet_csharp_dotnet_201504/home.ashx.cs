using System;
using System.Collections.Generic;
using System.IO;

using System.Web;
using System.Web.Script.Serialization;
using System.Web.SessionState;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;

using Gautier.OOHtml.Models;
using Gautier.OOHtml.Data;

namespace Gautier.OOHtml.Example.UI 
{
	public class Home : HomeBase, IHttpHandler, IRequiresSessionState 
	{
		public void ProcessRequest(HttpContext context)
		{
			var DocumentContexts = CreateDocumentContexts("Object Oriented HTML", null, null);

			BuildDocument(context, DocumentContexts.Item2);

			RenderDocument(context, DocumentContexts.Item1);

			return;
		}

		public void BuildDocument(HttpContext context, HtmlGenericControl documentContext)
		{
			var Elements = new List<HtmlGenericControl>();

			var CurrentElement = new HtmlGenericControl("label");
			CurrentElement.Attributes.Add("id", "FileInputLabel");
			CurrentElement.Attributes.Add("name", CurrentElement.Attributes["id"]);
			CurrentElement.Attributes.Add("for", "clientfile");
			CurrentElement.InnerText = "File";

			Elements.Add(CurrentElement);
			
			CurrentElement = new HtmlGenericControl("form");
			CurrentElement.Attributes.Add("id", "fileuploadform");
			CurrentElement.Attributes.Add("name", CurrentElement.Attributes["id"]);
			CurrentElement.Attributes.Add("method", "post");
			CurrentElement.Attributes.Add("enctype", "multipart/form-data");
			CurrentElement.Attributes.Add("action", "home.ashx");

			Elements.Add(CurrentElement);

			var FileForm = CurrentElement;

			CurrentElement = new HtmlGenericControl("input");
			CurrentElement.Attributes.Add("id", "clientfile");
			CurrentElement.Attributes.Add("name", CurrentElement.Attributes["id"]);
			CurrentElement.Attributes.Add("type", "file");
			CurrentElement.Attributes.Add("accept", ".txt");

			FileForm.Controls.Add(CurrentElement);

			CurrentElement = new HtmlGenericControl("input");
			CurrentElement.Attributes.Add("id", "fileuploadbutton");
			CurrentElement.Attributes.Add("name", CurrentElement.Attributes["id"]);
			CurrentElement.Attributes.Add("type", "submit");
			CurrentElement.Attributes.Add("value", "Upload File");
			
			FileForm.Controls.Add(CurrentElement);

			foreach(var Element in Elements)
			{
				documentContext.Controls.Add(Element);
			}

			var DataNodes = HandleFileTransmit(context, documentContext);

			var DbInstance = new ScienceBaseDbMediator();

			DbInstance.UpdateNodes(DataNodes);
			
			DataNodes = DbInstance.GetNodes();

			CurrentElement = new HtmlGenericControl("div");
			CurrentElement.InnerText = "data base results";

			documentContext.Controls.Add(CurrentElement);

			foreach(var DataNode in DataNodes)
			{
				var NodeFields = new List<Tuple<string,string>>
				{
					new Tuple<string, string>("Group Id", Convert.ToString(DataNode.GroupId)),
					new Tuple<string, string>("Id", DataNode.Id),
					new Tuple<string, string>("Title", DataNode.Title),
					new Tuple<string, string>("Summary", DataNode.Summary),
					new Tuple<string, string>("Url", DataNode.Url),
					new Tuple<string, string>("Has Children", Convert.ToString(DataNode.HasChildren)),
					new Tuple<string, string>("Rel", DataNode.Rel),
				};

				var NodeFieldOutput = new List<string>();

				foreach(var NodeField in NodeFields)
				{
					NodeFieldOutput.Add(string.Format("{0}: {1}", NodeField.Item1, NodeField.Item2));
				}

				CurrentElement = new HtmlGenericControl("div");
				CurrentElement.InnerText = string.Format("{0} {1}", string.Join(" ", NodeFieldOutput.ToArray()), Environment.NewLine);

				documentContext.Controls.Add(CurrentElement);
			}

			return;
		}

		private List<ScienceBaseNode> HandleFileTransmit(HttpContext context, HtmlGenericControl documentContext)
		{
			var DataNodes = new List<ScienceBaseNode>();

			if(null != context.Request["fileuploadbutton"])
			{
				var FileContext = context.Request.Files["clientfile"];
				var JSONText = string.Empty;

				if(null != FileContext && FileContext.ContentLength > 0)
				{
					var CurrentStreamReader = new StreamReader(FileContext.InputStream);

					using(CurrentStreamReader)
					{
						JSONText = CurrentStreamReader.ReadToEnd();
					}
				}
				
				if(string.Empty != JSONText)
				{
					var JSONReader = new JavaScriptSerializer();

					var JSONRoot = JSONReader.DeserializeObject(JSONText) as Dictionary<string, object>;

					/*var CurrentElement = new HtmlGenericControl("div");
					CurrentElement.InnerText = JSONRoot.GetType().ToString();
					
					documentContext.Controls.Add(CurrentElement);*/

					if(JSONRoot != null)
					{
						ExtractJSONStreamValues(DataNodes, JSONRoot, CreateDataNode(DataNodes, 0), 0);
					}
				}
			}

			return DataNodes;
		}

		private static ScienceBaseNode CreateDataNode(List<ScienceBaseNode> dataNodes, int grpId)
		{
			var DataNode = new ScienceBaseNode(grpId);
			
			dataNodes.Add(DataNode);
			
			return DataNode;
		}

		private void ExtractJSONStreamValues(List<ScienceBaseNode> dataNodes, Dictionary<string, object> values, ScienceBaseNode dataNode, int depth)
		{
			foreach(var Item in values)
			{
				if(Item.Value is Dictionary<string, object>)
				{
					var NewDepth = (1 + depth);

					ExtractJSONStreamValues(dataNodes, Item.Value as Dictionary<string, object>, CreateDataNode(dataNodes, NewDepth), NewDepth);
				}
				else if (Item.Value is object[])
				{
					ExtractJSONStreamValues(dataNodes, Item.Value as object[], depth);
				}
				else
				{
					dataNode.Read(depth, Item);
				}
			}

			return;
		}

		private void ExtractJSONStreamValues(List<ScienceBaseNode> dataNodes, object[] values, int depth)
		{
			foreach(var Item in values)
			{
				if(Item is Dictionary<string, object>)
				{
					var NewDepth = (1 + depth);
					
					ExtractJSONStreamValues(dataNodes, Item as Dictionary<string, object>, CreateDataNode(dataNodes, NewDepth), NewDepth);
				}
				else
				{
					var ErrorMessage = string.Format("Bottom: Type is {0} and ToString {1}", Item.GetType(), Item);
					throw new ApplicationException(ErrorMessage);
				}
			}

			return;
		}		

		private void HandleFileTransmitToResponseOutput(HttpContext context, HtmlGenericControl documentContext)
		{
			if(null != context.Request["fileuploadbutton"])
			{
				var FileContext = context.Request.Files["clientfile"];

				if(null != FileContext && FileContext.ContentLength > 0)
				{
					var CurrentElement = new HtmlGenericControl("div");
					documentContext.Controls.Add(CurrentElement);

					var CurrentStreamReader = new StreamReader(FileContext.InputStream);

					using(CurrentStreamReader)
					{
						CurrentElement.InnerText = CurrentStreamReader.ReadToEnd();
					}
				}
				else
				{
					var Details = new List<string>{
						" File Context Null " +
						(FileContext == null ? "yes" : "no")
						, "Request File Count " + 
						Convert.ToString(context.Request.Files.Count)
					};

					var CurrentElement = new HtmlGenericControl("div");
				
					CurrentElement.InnerText = string.Join(",", Details.ToArray());
				
					documentContext.Controls.Add(CurrentElement);
				
				}
			}

			return;
		}

		public bool IsReusable
		{
			get
			{
				return false;
			}
		}
	}
}
