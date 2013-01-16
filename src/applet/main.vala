/* applet/main.vala
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


// pick up the package version from the build system
extern const string VERSION;


namespace LedBorg
{

	// this class is just to get the app running
	public class Main : Object
	{

		// options and defaults
		private static bool _show_version = false;
		private static string _host = "127.0.0.1";
		private static uint _port = 9999;
		private const OptionEntry[] options = {
			{"ledborg-host", 'h', 0, OptionArg.STRING, ref _host, "Specify the server hostname or IP address", "HOST OR IP ADDRESS"},
			{"ledborg-port", 'p', 0, OptionArg.INT, ref _port, "Specify the server port", "PORT"},
			{"version", 'V', 0, OptionArg.NONE, ref _show_version, "Show version information", null},
			{null}
		};



		// main method
		static int main (string[] args)
		{
			// handle options
			try {
				var opt = new OptionContext("");
				opt.set_summary("LedBorg Control Applet %s is a systray app that allows you to control an LedBorg server running on a Raspberry Pi".printf(VERSION));
				opt.set_help_enabled(true);
				opt.add_main_entries(options, null);
				opt.parse(ref args);
			}
			catch(GLib.OptionError e) {
				GLib.stderr.printf("Error: %s\n", e.message);
				GLib.stderr.printf("Run '%s --help' to see a full list of available options\n", args[0]);
				return 1;
			}


			// show version information
			if(_show_version)
			{
				stdout.printf("LedBorg Control Applet version %s\n", VERSION);
				return 0;
			}


			Gtk.init(ref args);

			LedBorgControlApplet app = new LedBorgControlApplet(_host, (uint)_port);
			//app.server_host = _host;
			//app.server_port = (int) _port;

			Gtk.main();


			return 0;
		}

	}

}

