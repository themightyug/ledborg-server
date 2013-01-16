/* applet/LedBorgClient.vala
 *
 * Copyright (C) 2013  Ross Taylor
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author:
 * 	Ross Taylor <the.mighty.ug@gmail.com>
 */

using GLib;
using Soup;


namespace LedBorg
{

	public class LedBorgClient : GLib.Object
	{
		private Soup.SessionAsync session = new Soup.SessionAsync();


		public string server_host { get; set; default="127.0.0.1"; }
		public uint server_port { get; set; default=9999; }


		// constructor with ip and port
		public LedBorgClient(string host, uint port)
		{
			this.server_host = host;
			this.server_port = port;
		}


		private string generate_url(string action, Colour? colour)
		{
			string url = "http://%s:%d/%s".printf(this.server_host, (int)this.server_port, action);
			
			if(colour != null)
			{
				url += url.printf("?red=%d&green=%d&blue=%d", colour.red, colour.green, colour.blue);
			}
			
			return url;
		}


		// get current colour
		public Colour get_colour_from_server() throws IOError.COMMUNICATION_BREAKDOWN
		{
			Colour colour = Colour();
			string url = generate_url("GetColour", null);

			Soup.Message message = new Soup.Message("GET", url);
			uint status = session.send_message(message);

			if(status == Soup.KnownStatusCode.OK)
			{
				colour = Colour.with_rgb(message.response_headers["Colour-LedBorg"]);
			}
			else
			{
				throw new IOError.COMMUNICATION_BREAKDOWN("Failed to communicate with server at %s - %d %s".printf(url, (int)status, message.reason_phrase));
			}
			
			return colour;
		}
		

	}

}


