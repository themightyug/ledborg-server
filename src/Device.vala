/* Device.vala
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
using Posix;


namespace LedBorg
{

	// Handles communication with the LedBorg device
	public class Device : Object
	{
	
		// define the device file
		static const string DEVICE = "/dev/ledborg";

	
		// get the current colour value
		public static Colour get_colour() throws IOError.GENERAL, IOError.FILE_NOT_FOUND
		{
			string colour_text = "";
		
			// check file exists (if not, then either device or driver not present)
			File file = File.new_for_path(DEVICE);
			if(file.query_exists())
			{
				try
				{
					size_t length;
					FileUtils.get_contents(DEVICE, out colour_text, out length);
				}
				catch (GLib.FileError e)
				{
					throw new IOError.GENERAL(e.message);
				}
			}
			else
			{
				throw new IOError.FILE_NOT_FOUND("Device or driver not present. %s not found.".printf(DEVICE));
			}
		
			return Colour.with_rgb(colour_text);
		}

	
	
		// set colour value
		public static void set_colour(Colour colour) throws IOError.FILE_NOT_FOUND
		{
			// check file exists (if not, then either device or driver not present)
			File file = File.new_for_path(DEVICE);
			if(file.query_exists())
			{
				/*
				Here we use posix file handling to write to the file instead of
				vala's gio file handling, as we don't want the safety of
				gio getting in the way when operating in /dev
				*/
				// open the file for writing
				Posix.FILE f = Posix.FILE.open(DEVICE, "w");
			
				// write the colour string to the file
				f.puts(colour.get_ledborg_value());
			}
			else
			{
				throw new IOError.FILE_NOT_FOUND("Device or driver not present. %s not found.".printf(DEVICE));
			}
		}
	
	}

}


