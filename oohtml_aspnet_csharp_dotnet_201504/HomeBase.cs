using System;
using System.Web;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Collections.Generic;

namespace Gautier.OOHtml.Example.UI
{
	public class HomeBase
	{
		public void RenderDocument(HttpContext context, HtmlGenericControl documentRoot)
		{
			context.Response.Write("<!DOCTYPE html>");

			documentRoot.RenderControl(new XhtmlTextWriter(context.Response.Output));
			
			return;
		}

		public Tuple<HtmlGenericControl, HtmlGenericControl> CreateDocumentContexts(string title, List<string> styleSheetLinks, List<string> javaScriptLinks)
		{
			var WebDocumentContext 	= new HtmlGenericControl("html");
			var WebDocumentHeading 	= new HtmlGenericControl("head");
			var WebDocumentTitle 	= new HtmlGenericControl("title");
			var WebDocumentBody 	= new HtmlGenericControl("body");
			var WebDocumentBodyRoot = new HtmlGenericControl("div");

			WebDocumentHeading.Controls.Add(WebDocumentTitle);

			WebDocumentTitle.InnerText = title;

			if(null != styleSheetLinks)
			{
				foreach(var Item in styleSheetLinks)
				{
					var CssHref = new HtmlGenericControl("link");
					CssHref.Attributes.Add("rel", Item);
				
					WebDocumentHeading.Controls.Add(CssHref);
				}
			}

			if(null != javaScriptLinks)
			{
				foreach(var Item in javaScriptLinks)
				{
					var JsHref = new HtmlGenericControl("script");
					JsHref.Attributes.Add("type", "text/javascript");
					JsHref.Attributes.Add("src", Item);
				
					WebDocumentHeading.Controls.Add(JsHref);
				}
			}
			
			var WebDocumentContextControls = new List<HtmlGenericControl>{
				WebDocumentHeading, WebDocumentBody
			};
			
			foreach(var Item in WebDocumentContextControls)
			{
				WebDocumentContext.Controls.Add(Item);
			}
			
			WebDocumentBody.Controls.Add(WebDocumentBodyRoot);

			return new Tuple<HtmlGenericControl, HtmlGenericControl>(WebDocumentContext, WebDocumentBodyRoot);
		}
	}
}
