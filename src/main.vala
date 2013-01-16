/* main.vala
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



namespace LedBorg
{

	// this class is just to get the app running
	public class Main : Object
	{

		// options and defaults
		static int listen_port = 9999;
		const OptionEntry[] options = {
			{"port", 'p', 0, OptionArg.INT, ref listen_port, "Specify which port to listen on", null},
			{null}
		};


		// main method
		static int main (string[] args)
		{
			// handle options
			try {
				var opt = new OptionContext("");
				opt.set_help_enabled(true);
				opt.add_main_entries(options, null);
				opt.parse(ref args);
			}
			catch(GLib.Error e) {
				GLib.stderr.printf("Error: %s\n", e.message);
				GLib.stderr.printf("Run '%s --help' to see a full list of available options\n", args[0]);
				return 1;
			}
			
			// create new LedBorgServer to listen on the specified port
			LedBorgServer server = new LedBorgServer.with_listen_port(listen_port);
			
			// run the server
			server.run();


			return 0;
		}

	}

}

