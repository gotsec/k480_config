#include "main.h"

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/hidraw.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <dirent.h>

/**
 * Print help page
 *
 * @param binary binary name (from argv)
 */
void print_help (char *binary)
{
  printf ("\nUsage\n\"%s 1\" to enable Fn keys or \"%s 0\" to disable them. Bye.\n", binary, binary);
}

/**
 * Send commands, or rather key sequences directly to the keyboard
 *
 * @param fd file descriptior to write to
 * @param buf what to write
 * @param len how long it is
 * @return 0 if successful
 */
int send_commands (int fd, const char *buf, int len)
{
  long response;
  response = write (fd, buf, len);

  // check if the key sequence were sent
  // successfully to the specified device
  if (response >= 0)
    {
      printf ("Successfully sent command to device");
      return 0;
    }
  else
    {
      // an error occurred
      printf ("Error occurred while writing to device, error no: %d", errno);
      perror ("write");
      return 67;
    }
}

/**
 * Get device file names for all devices starting with: hidraw*
 *
 * @param dev_files the hidraw device files currently attached
 * @return count of hid files (zero-based for easier use with arrays)
 */
int get_hid_devices (char *dev_files[10])
{
  const int max_file_count = 10;
  DIR *path;
  struct dirent *dir;

  path = opendir ("/dev/");

  if (path)
    {
      int file_index = 0;

      while ((dir = readdir (path)) != NULL || file_index >= max_file_count)
        {
          if (strncmp ("hidraw", dir->d_name, 6) != 0)
            {
              // TODO: Only debug
              printf ("MISS... \"%s\"\n", dir->d_name);
              continue;
            }

          // TODO: Only debug
          printf ("FOUND! \"%s\"\n", dir->d_name);

          dev_files[file_index] = dir->d_name;
          file_index++;
        }

      closedir (path);
      return file_index;
    }
}

/**
 * Configurate if the Fn keys should be used as function
 * keys (1), or as their default purpose (0).
 *
 * ./k480_config 1 will turn on the Fn keys
 * ./k480_config 0 will turn off the Fn keys
 *
 */
int main (int argc, char **argv)
{
  printf ("Fn keys behavior configurator\n(ONLY for \"Logitech K480\"!)");

  if (argc != 2)
    {
      print_help (argv[0]);
      return 1;
    }

  char *hid_devices[10];
  int device_count = get_hid_devices (hid_devices);

  for (int i = 0; i < device_count; i++)
    {
      printf ("* %s (index: %d)\n", hid_devices[i], i);
    }

  return 0;
}
