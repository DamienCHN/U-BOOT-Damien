/*
 * Copyright (c) 2011 The Chromium OS Authors.
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * Operating System Interface
 *
 * This provides access to useful OS routines from the sandbox architecture
 */

/**
 * Access to the OS read() system call
 *
 * \param fd	File descriptor as returned by os_open()
 * \param buf	Buffer to place data
 * \param count	Number of bytes to read
 * \return number of bytes read, or -1 on error
 */
ssize_t os_read(int fd, void *buf, size_t count);

/**
 * Access to the OS write() system call
 *
 * \param fd	File descriptor as returned by os_open()
 * \param buf	Buffer containing data to write
 * \param count	Number of bytes to write
 * \return number of bytes written, or -1 on error
 */
ssize_t os_write(int fd, const void *buf, size_t count);

/**
 * Access to the OS open() system call
 *
 * \param pathname	Pathname of file to open
 * \param flags		Flags, like O_RDONLY, O_RDWR
 * \return file descriptor, or -1 on error
 */
int os_open(const char *pathname, int flags);

/**
 * Access to the OS close() system call
 *
 * \param fd	File descriptor to close
 * \return 0 on success, -1 on error
 */
int os_close(int fd);

/**
 * Access to the OS exit() system call
 *
 * This exits with the supplied return code, which should be 0 to indicate
 * success.
 *
 * @param exit_code	exit code for U-Boot
 */
void os_exit(int exit_code);
