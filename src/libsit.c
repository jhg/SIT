/*
 * SIT Copyright (C) 2011 Jesús Hernández Gormaz
 *
 * This program is free software; you can redistribute it and/or modify it under
 *   the terms of the GNU General Public License as published by the Free
 *   Software Foundation; either version 3, or (at your option) any later
 *   version.
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 *   more details.
 * You should have received a copy of the GNU General Public License along with
 *   this program; if not, write to the Free Software Foundation, Inc., 675 Mass
 *   Ave, Cambridge, MA 02139, USA.
 */

//---------------------------------- HEADER ----------------------------------//

// Header of SIT file
struct SIT_header
  {
    // Version
    unsigned long int version_major;
    unsigned long int version_minor;
    unsigned long int version_revision;
    // Flags
    char flags;
  };

//---------------------------------- INDEX -----------------------------------//

// Type of element
enum SIT_index_element_type
  {
    undefined_type,
    directory,
    file
  };

// File element
struct SIT_file_element
  {
    // Type
    enum SIT_index_element_type type;
    // Absolute path
    char *path;
    // Name
    char *name;
    // Integrity and permissions
    char permisions[2];
    // Parent element
    struct SIT_index_element *parent;
    // Pointers to create a doubly linked list dynamics
    struct SIT_index_element *prev;
    struct SIT_index_element *next;
    // Global list
    struct SIT_index_element *global_prev;
    struct SIT_index_element *global_next;

    // Starting position (first byte)
    unsigned long int position;
    // Size of file in bytes (is calculated when load index)
    unsigned long int size;
  };

// Directory element
struct SIT_directory_element
  {
    // Type
    enum SIT_index_element_type type;
    // Absolute path
    char *path;
    // Name
    char *name;
    // Integrity and permissions
    char permisions[2];
    // Parent element
    union SIT_index_element *parent;
    // Pointers to create a doubly linked list dynamics
    union SIT_index_element *prev;
    union SIT_index_element *next;
    // Global list
    union SIT_index_element *global_prev;
    union SIT_index_element *global_next;

    // Elements in directory
    union SIT_index_element *elements;
  };

// Index element
union SIT_index_element
  {
    // Type
    enum SIT_index_element_type type;
    // File
    struct SIT_file_element file;
    // Directory
    struct SIT_directory_element directory;
  };

//----------------------------- SIT ARCHIVE FILE -----------------------------//

struct SIT_archive
  {
    // Header
    struct SIT_header *header;
    // Index
    struct SIT_index_element *root_directory;
  };

