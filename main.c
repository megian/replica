#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#define REP_VERSION "0.01"

// 0.01 - 2014-04-26 - Gabriel Mainberger

///////////////////////////////////////////////////////////////////////////////
// Stuctures

struct rep_file_header
{
        unsigned char identifier[4];       // local file header signature       [4 bytes] 0x49dfec17
        unsigned char on_disk_structure[2];// version needed to extract         [2 bytes]
        unsigned char general_flags[2];    // general purpose bit flag          [2 bytes]
        uuid_t replication_uuid;           // Replication UUID                  [36 bytes]
        unsigned char revision[16];        // Revision                          [16 bytes]
        unsigned char last_mod_time[2];    // last mod file time                [2 bytes]
        unsigned char last_mod_date[2];    // last mod file date                [2 bytes]
        unsigned char crc32;               // crc-32                            [4 bytes]
        unsigned char file_name_length;    // file name length                  [2 bytes]
        unsigned char extra_field_length;  // extra field length                [2 bytes]

};

typedef struct rep_file
{
        unsigned char identifier[4];
        uuid_t replication_uuid;

} rep_file_t;

///////////////////////////////////////////////////////////////////////////////
// Global Variables

///////////////////////////////////////////////////////////////////////////////
// Functions


void
rep_file_open ()
{
        FILE *fhd;

        fhd = fopen ("test.rep", "w");
        if (!fhd)
        {
                printf ("Unable to open file!\n");
                return;
        }

        fclose (fhd);
}

int
rep_file_read ()
{
    FILE *source_fhd;
    FILE *destination_fhd;
    char file_buffer[4096];
	int read_chars_in_buffer = 0;


        source_fhd = fopen ("test.rep", "r");
        if (source_fhd == NULL)
        {
                printf ("file error!\n");
                return 0;
        }

        destination_fhd = fopen ("test2.rep", "w");
        if (destination_fhd == NULL)
        {
                printf ("file error!\n");
                return 0;
        }

        while(1)
        {
                read_chars_in_buffer = fread (file_buffer, sizeof (char), sizeof (file_buffer), source_fhd);
		fwrite (file_buffer, sizeof (char), read_chars_in_buffer, destination_fhd);
		//printf("%i %s\n", read_chars_in_buffer, file_buffer);
                if (feof (source_fhd))
                        break;
        }

        fclose (source_fhd);
	fclose (destination_fhd);
}

rep_file_t*
rep_file_header_init ()
{
        rep_file_t *file_header = NULL;
        unsigned char identifier[4] = {0x49, 0xdf, 0xec, 0x17};

        file_header = malloc (sizeof(struct rep_file));
        if (file_header != NULL)
        {
                // Copy file identifier
                memcpy (file_header->identifier, identifier, sizeof(identifier));

                // Generate UUID RFC 4122
                uuid_generate (file_header->replication_uuid);
        }
        return (file_header);
}

void
rep_file_header_print (rep_file_t *file_header)
{
        unsigned char unparsed_uuid_str[36];

        if (file_header == NULL) return;

        printf ("Identifier:\t0x%x%x%x%x\n", file_header->identifier[0],
                                   file_header->identifier[1],
                                   file_header->identifier[2],
                                   file_header->identifier[3]);

        uuid_unparse (file_header->replication_uuid, unparsed_uuid_str);

        printf ("UUID:\t\t%s\n", unparsed_uuid_str);
}

void
rep_header_free (rep_file_t *file_header) {
        free (file_header);
}

int main()
{
        unsigned char str[36];
        rep_file_t *file_header;

        printf("Replica %s\n\n", REP_VERSION);

        file_header = rep_file_header_init ();
        if (file_header != NULL)
        {
                rep_file_header_print (file_header);
                rep_header_free (file_header);
        }

	rep_file_read ();

        return(0);
}
