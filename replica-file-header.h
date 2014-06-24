/* -*-coding: utf-8;-*- */

/* replica-file-header.h
 * This file is part of Replica
 * Copyright (c) 2014, Gabriel Mainberger
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __REPLICA_FILE_HEADER_H__
#define __REPLICA_FILE_HEADER_H__

#include "replica.h"

struct replica_file_header {
	unsigned char identifier[4];		// local file header signature		[4 bytes] 0x49dfec17
	unsigned char on_disk_structure[2];	// version needed to extract		[2 bytes]
	unsigned char general_flags[2];		// general purpose bit flag			[2 bytes]
	uuid_t replication_uuid;			// Replication UUID					[36 bytes]
	unsigned char revision[16];			// Revision							[16 bytes]
	unsigned char last_mod_time[2];		// last mod file time				[2 bytes]
	unsigned char last_mod_date[2];		// last mod file date				[2 bytes]
	unsigned char crc32;				// crc-32							[4 bytes]
	unsigned char file_name_length;		// file name length					[2 bytes]
	unsigned char extra_field_length;	// extra field length				[2 bytes]
};

typedef struct replica_file {
	unsigned char identifier[4];
	uuid_t replication_uuid;

} replica_file_t;

replica_file_t* replica_file_header_init ();
void replica_file_header_free (replica_file_t *file_header);
void replica_file_header_print (replica_file_t *file_header);
bool replica_file_header_compare (char *possible_header);

#endif /* __REPLICA_FILE_H__ */
