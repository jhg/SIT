/*
 * SIT Copyright (C) 2011 Jesús Hernández Gormaz
 *
 * This program is free software; you can redistribute it and/or modify it under
 *   the terms of the GNU General Public License as published by the Free Software
 *   Foundation; either version 3, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 *   A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with
 *   this program; if not, write to the Free Software Foundation, Inc., 675 Mass
 *   Ave, Cambridge, MA 02139, USA.
 */

struct SIT_header
  {
    // Version
    unsigned long int version_major;
    unsigned long int version_minor;
    unsigned long int version_revision;
    // Flags
    char flags;
  };

struct SIT_index_element
  {
    // Absolute path
    char *path;
    // Starting position (first byte)
    unsigned long int position;
    // Size of file (in bytes)
    unsigned long int size;
    // Integrity and permissions
    char permisions[2];
  }

