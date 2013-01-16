/* Colour.vala
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

	// colour structure holds RGB brightness values and converts to and from HTML hex format
	public struct Colour
	{
		
		public int red;
		public int green;
		public int blue;


		// constructor with LedBorg colour value
		public Colour.with_rgb (string rgb)
		{
			red		= int.parse(rgb.substring(0, 1));
			green	= int.parse(rgb.substring(1, 1));
			blue	= int.parse(rgb.substring(2, 1));
		}

		// use LedBorg colour value as standard string representation
		public string to_string()
		{
			return get_ledborg_value();
		}

		// return LedBorg colour value
		public string get_ledborg_value()
		{
			StringBuilder c = new StringBuilder();
			
			c.append(red.to_string());
			c.append(green.to_string());
			c.append(blue.to_string());
			
			return c.str;
		}

		// return HTML hex colour value - with preceeding hash sign
		public string get_html_value()
		{
			/*
				conversions from ledborg brightness values to html brightness values
				0 = #00 = off
				1 = #cc = 'half' brightness
					 - actually appears to be more like 2/3 or 3/4 brightness
				2 = #ff = full brightness
			*/
			string[] lookup = {"00", "bb", "ff"};
		
			StringBuilder html = new StringBuilder("#");

			html.append(lookup[red]);
			html.append(lookup[green]);
			html.append(lookup[blue]);
			
			return html.str;
		}

	}

}

