/*
 * LedBorgControlApplet.vala
 * This file is part of LedBorg-Control-Applet
 *
 * Copyright (C) 2013 - Ross Taylor
 *
 * LedBorg-Control-Applet is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * LedBorg-Control-Applet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LedBorg-Control-Applet. If not, see <http://www.gnu.org/licenses/>.
 */


using GLib;
using Gtk;
using Gdk;
using Cairo;




namespace LedBorg
{

	public class LedBorgControlApplet : GLib.Object
	{
	
		public string server_host { get; set; }
		public uint server_port { get; set; }


		private StatusIcon trayicon;
        private int old_size;



		// constructor with ip and port
		public LedBorgControlApplet(string host, uint port)
		{
			this.server_host = host;
			this.server_port = port;

			this.trayicon = new StatusIcon();
			this.trayicon.set_visible(true);
			this.trayicon.set_name("LedBorg Control Applet");
			this.trayicon.set_title("LedBorg Control Applet");

			// This event is called when the user modifies the height of the pannel
			this.trayicon.size_changed.connect(this.repaint);

			// This event is called when the user clicks on the icon.
			// Assigned with an anonymous method to main_quit.
			//this.trayicon.activate.connect( () => { Gtk.main_quit(); } );
		}

		// Pixbuf callback to destroy the pixel buffer
		public void PixbufDestroyNotify (uint8* pixels)
		{
			delete pixels;
		}

	
		public bool timer()
		{
			// This callback repaints the systray canvas
			repaint();
			return false;
		}
	
	
		public bool repaint()
		{
			int size = this.trayicon.get_size();

			double red = 0;
			double green = 0;
			double blue = 0;

			LedBorgClient client = new LedBorgClient(this.server_host, this.server_port);
			Colour colour = client.get_colour_from_server();

			if(colour.to_string() != "")
			{
				red = (double) colour.red / 2;
				green = (double) colour.green / 2;
				blue = (double) colour.blue / 2;
			}
		
			// First, let's paint something in a Cairo Surface
			var canvas = new Cairo.ImageSurface(Cairo.Format.ARGB32, size, size);
			var ctx = new Cairo.Context(canvas);

			// This makes easier to scale the picture
			ctx.scale(size, size);

			ctx.set_source_rgb(red, green, blue);

			ctx.arc(0.5, 0.5, 0.3, 0, 6.283184);
			ctx.set_line_width(0.4);
			ctx.stroke();

			// the pixel buffer must remain after being created, so manual memory management is used here
			uint8* pixel_data = new uint8[size * size * 4];

			// create a new Pixbuf using the previous pixel_data memory as buffer
			// it is 8bit per pixel, RGB, with alpha, and the callback to free the pixel data is PixbufDestroyNotify()
			var pix = new Pixbuf.from_data((uint8[]) pixel_data, Gdk.Colorspace.RGB, true, 8, size, size, size*4, this.PixbufDestroyNotify);
				
			uint8 *p1 = pixel_data;
			uint8 *p2 = canvas.get_data();
			int counter;
			int max = size * size;;

			// Copy the surface to the pixbuf
			// (Format in surface is BGRA, but in Pixbuf is RGBA)
			for(counter=0;counter<max;counter++)
			{
				*p1    =*(p2+2);
				*(p1+1)=*(p2+1);
				*(p1+2)=*p2;
				*(p1+3)=*(p2+3);
				p1+=4;
				p2+=4;	
			}

			// Set pixmap in the systray
			this.trayicon.set_from_pixbuf(pix);

			// and set a timer to repaint the circle after one second
			Timeout.add(1000,timer);

			// Return true because the function had in account the new size, so the pannel has not to scale it
			return true;
		}

	
	}

}



