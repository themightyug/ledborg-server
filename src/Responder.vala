/*
 * Responder.vala
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

	public class Responder : Object
	{

		public static void respond_with_error(ref unowned Soup.Message msg, string error_message)
		{
			msg.set_status_full(Soup.KnownStatusCode.INTERNAL_SERVER_ERROR, error_message);
			msg.set_response("text/plain", Soup.MemoryUse.COPY, error_message.data);
		}


		public static void respond_with_colour(ref unowned Soup.Message msg, Colour colour, bool include_form)
		{
			string html;
			
			if(include_form)
			{
				html = generate_html_form(colour);
			}
			else
			{
				html = generate_html_colour(colour);
			}
			
			msg.response_headers.append("Colour-LedBorg", colour.get_ledborg_value());
			msg.response_headers.append("Colour-Html", colour.get_html_value());
			msg.set_status_full(Soup.KnownStatusCode.OK, "OK");
			msg.set_response("text/html", Soup.MemoryUse.COPY, html.data);
		}


		private static string generate_html_colour(Colour colour)
		{
			string html = """
				<div style="width: 64px; height: 20px; border: black solid 8px; background-color: %s;">
					&nbsp;
				</div>
			""".printf(colour.get_html_value());
			
			return html;
		}


		private static string generate_html_form(Colour colour)
		{
			string html;
			size_t html_length;

			string html_file_path = "%s/ledborg-server/ledborg-server.html".printf(Config.SYSCONFDIR);
			
			FileUtils.get_contents(html_file_path, out html, out html_length);
			html = html.printf(generate_html_colour(colour));
			
			return html;
		}


	}

}


