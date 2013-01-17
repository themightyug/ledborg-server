/*
 * LedBorgServer.vala
 * This file is part of LedBorg-Server
 *
 * Copyright (C) 2013 - Ross Taylor
 *
 * LedBorg-Server is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * LedBorg-Server is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LedBorg-Server. If not, see <http://www.gnu.org/licenses/>.
 */


using GLib;
using Soup;


namespace LedBorg
{

	public class LedBorgServer : Soup.Server
	{

		public LedBorgServer()
		{
		}
		

		public LedBorgServer.with_listen_port (int listen_port)
		{
			Object(port:listen_port);
			
			stderr.printf("listening on port %s\n", this.port.to_string());
			
			initialize_server();
		}
		
		
		public void initialize_server()
		{
			this.add_handler("/", handler_default);
			this.add_handler("/GetColour", handler_get_colour);
			this.add_handler("/SetColour", handler_set_colour);
		}


		// default handler
		public static void handler_default
		(Soup.Server server, Soup.Message msg, string path,
		GLib.HashTable<string, string>? query, Soup.ClientContext client)
		{
			
		}


		// get_colour handler
		public static void handler_get_colour
		(Soup.Server server, Soup.Message msg, string path,
		GLib.HashTable<string, string>? query, Soup.ClientContext client)
		{
			try
			{
				Colour current_colour = Device.get_colour();
				Responder.respond_with_colour(ref msg, current_colour);
			}
			catch (IOError e)
			{
				stderr.printf("IO Error: %s\n", e.message);
				Responder.respond_with_error(ref msg, e.message);
			}
		}
		
		
		// set_colour handler
		public static void handler_set_colour
		(Soup.Server server, Soup.Message msg, string path,
		GLib.HashTable<string, string>? query, Soup.ClientContext client)
		{
			try
			{
				Colour? colour = get_colour_from_query(query);
		
				if(colour != null)
				{
					Device.set_colour(colour);
					Responder.respond_with_colour(ref msg, colour);
				}
			}
			catch (RequestError e)
			{
				stderr.printf("Request Error: %s\n", e.message);
				Responder.respond_with_error(ref msg, e.message);
			}
			catch (IOError e)
			{
				stderr.printf("IO Error: %s\n", e.message);
				Responder.respond_with_error(ref msg, e.message);
			}
		}


		private static Colour? get_colour_from_query(GLib.HashTable<string, string>? query) throws RequestError
		{
			Colour? colour = null;
			
			if(query != null)
			{
				if(query["red"] != null && query["green"] != null && query["blue"] != null)
				{
					try
					{
						colour = Colour() {
							red		= int.parse(query["red"]),
							green	= int.parse(query["green"]),
							blue	= int.parse(query["blue"])
						};
					}
					catch (GLib.Error e)
					{
						throw new RequestError.COLOUR_REQUEST_INVALID("Failed to create colour from parameters: %s".printf(e.message));
					}
				}
				else
				{
					throw new RequestError.COLOUR_REQUEST_INVALID("Incorrect parameters");
				}
			}
			else
			{
				throw new RequestError.COLOUR_REQUEST_INVALID("No parameters found");
			}
			
			return colour;
		}
		
	}

}

