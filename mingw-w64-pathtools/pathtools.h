/*
      .Some useful path tools.
   Written by Ray Donnelly in 2014.
   Licensed under CC0. No warranty.
 */

#ifndef PATHTOOLS_H
#define PATHTOOLS_H

#include <unistd.h>
#if defined(__APPLE__)
#include <stdlib.h>
#else
#include <malloc.h>
#endif
#include <stdio.h>

char * malloc_copy_string(char const * original);

/* In-place replaces any '\' with '/' and any '//' with '/' */
void sanitise_path(char * path);

/* Uses a host OS specific function to determine the path of the executable,
   if IMPLEMENT_SYS_GET_EXECUTABLE_PATH is defined, otherwise uses argv0. */
int get_executable_path(char const * argv0, char * result, ssize_t max_size);

/* Where possible, in-place removes occourances of '.' and 'path/..' */
void simplify_path(char * path);

/* Allocates (via malloc) and returns the path to get from from to to. */
char * get_relative_path(char const * from, char const * to);

size_t split_path_list(char const * path_list, char split_char, char *** arr);

/* Advances path along by the amount that removes n prefix folders. */
char const *
strip_n_prefix_folders(char const * path, size_t n);

/* NULL terminates path to remove n suffix folders. */
void
strip_n_suffix_folders(char * path, size_t n);

char * get_relocated_path_list(char const * from, char const * to_path_list);

#endif /* PATHTOOLS_H */
