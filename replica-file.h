/* -*-coding: utf-8;-*- */

/* replica-file.h
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

#ifndef __REPLICA_FILE_H__
#define __REPLICA_FILE_H__

#include "replica.h"
#include "replica-file-header.h"

void replica_file_open (replica_file_t *file_header, char *filename);
void replica_file_read ();
void replica_file_data_copy ();

#endif /* __REPLICA_FILE_H__ */
