/* -*-coding: utf-8;-*- */

/* main.c
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

#include "replica.h"
#include "replica-file.h"
#include "replica-file-header.h"

#define REP_VERSION "0.02"

// 0.01 - 2014-04-26 - Gabriel Mainberger
// 0.02 - 2014-06-24 - Gabriel Mainberger

int main() {
	replica_file_t *file_header;

	printf("Replica %s\n\n", REP_VERSION);

	file_header = replica_file_header_init ();
	if (file_header != NULL) {
		replica_file_header_print (file_header);
		replica_file_header_free (file_header);
	}

	replica_file_read ();

	return (0);
}
