namespace Gautier.OOHtml
{
	using System;
	using System.Collections;
	using System.ComponentModel;
	using System.Web;
	using System.Web.SessionState;

	public class Global : System.Web.HttpApplication
	{
		internal const string WebAccountDbKey = "10e2f7ad-288c-4496-a182-d6d0dc342a20";
		internal const string WebAccountUKey = "t1CizCQjHGUh0foEMcutiA==";
		internal const string WebAccountUser = "webvisitor";
		
		protected void Application_Start (Object sender, EventArgs e)
		{
		}

		protected void Session_Start (Object sender, EventArgs e)
		{
		}

		protected void Application_BeginRequest (Object sender, EventArgs e)
		{
		}

		protected void Application_EndRequest (Object sender, EventArgs e)
		{
		}

		protected void Application_AuthenticateRequest (Object sender, EventArgs e)
		{
		}

		protected void Application_Error (Object sender, EventArgs e)
		{
		}

		protected void Session_End (Object sender, EventArgs e)
		{
		}

		protected void Application_End (Object sender, EventArgs e)
		{
		}
	}
}

