/*
 * IOError.vala
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


// define exception
public errordomain IOError
{
	FILE_NOT_FOUND,
	COMMUNICATION_BREAKDOWN,
	GENERAL
}


