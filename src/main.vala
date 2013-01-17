/*
 * main.vala
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


// pick up the package version from the build system
extern const string VERSION;


namespace LedBorg
{

	// this class is just to get the app running
	public class Main : Object
	{

		// options and defaults
		private static bool _show_version = false;
		private static int listen_port = 9999;
		private const OptionEntry[] options = {
			{"port", 'p', 0, OptionArg.INT, ref listen_port, "Specify which port to listen on", null},
			{"version", 'V', 0, OptionArg.NONE, ref _show_version, "Show version information", null},
			{null}
		};


		// main method
		static int main (string[] args)
		{
			// handle options
			try {
				var opt = new OptionContext("");
				opt.set_summary("LedBorg Server %s is a simple server that allows network control an LedBorg add-on for the Raspberry Pi".printf(VERSION));
				opt.set_help_enabled(true);
				opt.add_main_entries(options, null);
				opt.parse(ref args);
			}
			catch(GLib.Error e) {
				GLib.stderr.printf("Error: %s\n", e.message);
				GLib.stderr.printf("Run '%s --help' to see a full list of available options\n", args[0]);
				return 1;
			}


			// show version information
			if(_show_version)
			{
				stdout.printf("LedBorg Server version %s\n", VERSION);
				return 0;
			}

			
			// create new LedBorgServer to listen on the specified port
			LedBorgServer server = new LedBorgServer.with_listen_port(listen_port);
			
			// run the server
			server.run();


			return 0;
		}

	}

}

