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
 
#include "replica-file.h"

void replica_file_open (replica_file_t *file_header, char *filename) {
	FILE *file_handle;
	
	// File header is NULL; STOP
	if (file_header == NULL) return;
	// File name is NULL: STOP
	if (filename == NULL) return;

	file_handle = fopen (filename, "w");
	if (file_handle == NULL) {
		printf ("Unable to open file!\n");
		return;
	}

	fclose (file_handle);
}

void replica_file_read_header (replica_file_t *file_header, FILE *file_handle) {
	char file_buffer[sizeof (struct replica_file_header)];
	size_t read_chars_in_buffer = 0;
	
	// File header is NULL; STOP
	if(file_handle == NULL) return;
	// File handle is NULL: STOP
	if (file_handle == NULL) return;
	
	read_chars_in_buffer = fread (file_buffer, sizeof (char), sizeof (struct replica_file_header), file_handle);
	if (read_chars_in_buffer == 0) { printf ("empty file\n"); return; }
	if (read_chars_in_buffer < sizeof (struct replica_file_header)) { printf ("invalid header\n"); return; }
	
	if (replica_file_header_compare (file_buffer) == false) { printf ("invalid header identifier\n"); return; }
	
}

void replica_file_read () {
	FILE *source_fhd;
	FILE *destination_fhd;
	char file_buffer[4096];
	int read_chars_in_buffer = 0;

	source_fhd = fopen ("test.rep", "r");
	if (source_fhd == NULL) {
		printf ("file error!\n");
		return;
	}

	destination_fhd = fopen ("test2.rep", "w");
	if (destination_fhd == NULL) {
		printf ("file error!\n");
		return;
}

	while (feof (source_fhd)) {
		read_chars_in_buffer = fread (file_buffer, sizeof (char), sizeof (file_buffer), source_fhd);
		fwrite (file_buffer, sizeof (char), read_chars_in_buffer, destination_fhd);
		//printf("%i %s\n", read_chars_in_buffer, file_buffer);
	}

	fclose (source_fhd);
	fclose (destination_fhd);
}

void replica_file_data_copy () {
	FILE *source_fhd;
	FILE *destination_fhd;
	char file_buffer[4096];
	int read_chars_in_buffer = 0;

	source_fhd = fopen ("test.rep", "r");
	if (source_fhd == NULL) {
		printf ("file error!\n");
		return;
	}

	destination_fhd = fopen ("test2.rep", "w");
	if (destination_fhd == NULL) {
		printf ("file error!\n");
		return;
}

	while (feof (source_fhd)) {
		read_chars_in_buffer = fread (file_buffer, sizeof (char), sizeof (file_buffer), source_fhd);
		fwrite (file_buffer, sizeof (char), read_chars_in_buffer, destination_fhd);
		//printf("%i %s\n", read_chars_in_buffer, file_buffer);
	}

	fclose (source_fhd);
	fclose (destination_fhd);
}

