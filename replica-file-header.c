/* -*-coding: utf-8;-*- */

/* replica-file.c
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
 
#include "replica-file-header.h"

replica_file_t* replica_file_header_init () {
	replica_file_t *file_header = NULL;
	const unsigned char identifier[4] = {0x49, 0xdf, 0xec, 0x17};

	file_header = malloc (sizeof(struct replica_file));
	if (file_header == NULL) return (NULL);
	
	// Copy file identifier
	memcpy (file_header->identifier, identifier, sizeof (identifier));

	// Generate UUID RFC 4122
	uuid_generate (file_header->replication_uuid);

	return (file_header);
}

void replica_file_header_free (replica_file_t *file_header) {
	if (file_header == NULL) return;
	free (file_header);
}

void replica_file_header_print (replica_file_t *file_header) {
	char unparsed_uuid_str[36];

	// File header is NULL: STOP
	if (file_header == NULL) return;

	printf ("Identifier:\t0x%x%x%x%x\n",	file_header->identifier[0],
											file_header->identifier[1],
											file_header->identifier[2],
											file_header->identifier[3]);

	uuid_unparse (file_header->replication_uuid, unparsed_uuid_str);

	printf ("UUID:\t\t%s\n", unparsed_uuid_str);
}

bool replica_file_header_compare (char *possible_header) {
	const unsigned char identifier[4] = {0x49, 0xdf, 0xec, 0x17};
	
	// File header is NULL: STOP
	if (possible_header == NULL) return false;

	if ((possible_header[0] == identifier[0]) &&
		(possible_header[1] == identifier[1]) &&
		(possible_header[2] == identifier[2]) &&
		(possible_header[3] == identifier[3])) {
		return true;
	} else {
		return false;
	}
}